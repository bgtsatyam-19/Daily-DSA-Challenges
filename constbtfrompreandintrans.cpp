//Construct Binary Tree from Preorder and Inorder Traversa
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) return nullptr;
        
        int rootVal = preorder[0];
        TreeNode* root = new TreeNode(rootVal);
        
        auto it = find(inorder.begin(), inorder.end(), rootVal);
        int leftSize = distance(inorder.begin(), it);
        
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + leftSize);
        vector<int> rightPreorder(preorder.begin() + 1 + leftSize, preorder.end());
        vector<int> leftInorder(inorder.begin(), it);
        vector<int> rightInorder(it + 1, inorder.end());
        
        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);
        
        return root;
    }
};
int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    
    Solution solution;
    TreeNode* root = solution.buildTree(preorder, inorder);
    
    // Function to print the tree in order (for verification)
    function<void(TreeNode*)> printInOrder = [&](TreeNode* node) {
        if (!node) return;
        printInOrder(node->left);
        cout << node->val << " ";
        printInOrder(node->right);
    };
    
    cout << "Inorder traversal of the constructed binary tree:" << endl;
    printInOrder(root);
    cout << endl;
    
    // Clean up memory (delete nodes)
    function<void(TreeNode*)> deleteTree = [&](TreeNode* node) {
        if (!node) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    };
    
    deleteTree(root);
    
    return 0;
}
