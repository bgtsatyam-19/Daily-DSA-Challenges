//Minimum Absolute Difference in BST
//
// Definition for a binary tree node.
 
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
    int getMinimumDifference(TreeNode* root) {
        vector<int> values;
        inorderTraversal(root, values);
        
        int minDiff = INT_MAX;
        for (size_t i = 1; i < values.size(); i++) {
            minDiff = min(minDiff, values[i] - values[i - 1]);
        }
        
        return minDiff;
    }
    void inorderTraversal(TreeNode* node, vector<int>& values) {
        if (!node) return;
        
        inorderTraversal(node->left, values);
        values.push_back(node->val);
        inorderTraversal(node->right, values);
    }
};
int main() {
    Solution solution;
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    
    int result = solution.getMinimumDifference(root);
    cout << "Minimum absolute difference in BST: " << result << endl;
    
    // Clean up memory
    delete root->right->left;
    delete root->right;
    delete root;
    
    return 0;
}
