//Diameter of Binary Tree
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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        depth(root, diameter);
        return diameter;
    }
    
    int depth(TreeNode* node, int& diameter) {
        if (!node) return 0;
        
        int leftDepth = depth(node->left, diameter);
        int rightDepth = depth(node->right, diameter);
        
        diameter = max(diameter, leftDepth + rightDepth);
        
        return max(leftDepth, rightDepth) + 1;
    }
};
int main() {
    Solution solution;
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    int result = solution.diameterOfBinaryTree(root);
    cout << "Diameter of the binary tree: " << result << endl;
    
    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    
    return 0;
}
