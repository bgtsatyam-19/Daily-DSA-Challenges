//Validate Binary Search Tree
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
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
    }
private:
    bool isValidBSTHelper(TreeNode* node, long minVal, long maxVal) {
        if (!node) return true;
        if (node->val <= minVal || node->val >= maxVal) return false;
        return isValidBSTHelper(node->left, minVal, node->val) &&
               isValidBSTHelper(node->right, node->val, maxVal);
    }
};
int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    
    Solution solution;
    bool result = solution.isValidBST(root);
    
    if (result) {
        cout << "The binary tree is a valid binary search tree." << endl;
    } else {
        cout << "The binary tree is not a valid binary search tree." << endl;
    }
    
    // Clean up memory
    delete root->left;
    delete root->right;
    delete root;
    
    return 0;
}
