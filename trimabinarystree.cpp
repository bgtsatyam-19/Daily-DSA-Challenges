//Trim a Binary Search Tree
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return nullptr;
        if (root->val < low) return trimBST(root->right, low, high);
        if (root->val > high) return trimBST(root->left, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
int main() {
    Solution solution;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(0);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(1);

    int low = 1, high = 3;
    TreeNode* trimmedRoot = solution.trimBST(root, low, high);
    
    // Function to print the tree in-order
    function<void(TreeNode*)> inOrder = [&](TreeNode* node) {
        if (!node) return;
        inOrder(node->left);
        cout << node->val << " ";
        inOrder(node->right);
    };

    cout << "Trimmed BST (in-order): ";
    inOrder(trimmedRoot);
    cout << endl;

    return 0;
}
