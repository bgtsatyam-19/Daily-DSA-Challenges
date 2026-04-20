//Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty()) return nullptr;
        
        int rootVal = postorder.back();
        TreeNode* root = new TreeNode(rootVal);
        
        auto it = find(inorder.begin(), inorder.end(), rootVal);
        int leftSize = distance(inorder.begin(), it);
        
        vector<int> leftInorder(inorder.begin(), it);
        vector<int> rightInorder(it + 1, inorder.end());
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftSize);
        vector<int> rightPostorder(postorder.begin() + leftSize, postorder.end() - 1);
        
        root->left = buildTree(leftInorder, leftPostorder);
        root->right = buildTree(rightInorder, rightPostorder);
        
        return root;
    }
};
int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    
    Solution solution;
    TreeNode* root = solution.buildTree(inorder, postorder);
    
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
