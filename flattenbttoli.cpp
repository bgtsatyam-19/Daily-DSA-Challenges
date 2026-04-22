//Flatten Binary Tree to Linked List
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
    void flatten(TreeNode* root) {
        if (!root) return;
        
        flatten(root->left);
        flatten(root->right);
        
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = nullptr;
        
        TreeNode* current = root;
        while (current->right) {
            current = current->right;
        }
        current->right = temp;
    }
};
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution solution;
    solution.flatten(root);

    cout << "Flattened tree (linked list): ";
    TreeNode* current = root;
    while (current) {
        cout << current->val << " ";
        current = current->right;
    }
    cout << endl;

    // Clean up memory (delete nodes)
    function<void(TreeNode*)> deleteTree = [&](TreeNode* node) {
        if (!node) return;
        deleteTree(node->right);
        delete node;
    };
    deleteTree(root);

    return 0;
}
