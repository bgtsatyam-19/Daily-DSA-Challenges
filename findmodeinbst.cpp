//Find Mode in Binary Search Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    void inorder(TreeNode* root, vector<int>& nums) {
        if (!root) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
    
    vector<int> findMode(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        
        unordered_map<int, int> freq;
        int maxFreq = 0;
        
        for (int num : nums) {
            freq[num]++;
            maxFreq = max(maxFreq, freq[num]);
        }
        
        vector<int> modes;
        for (const auto& pair : freq) {
            if (pair.second == maxFreq) {
                modes.push_back(pair.first);
            }
        }
        
        return modes;
    }
};
int main() {
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);
    
    vector<int> modes = solution.findMode(root);
    cout << "Mode(s) in the BST: ";
    for (int mode : modes) {
        cout << mode << " ";
    }
    cout << endl;
    
    // Clean up memory
    delete root->right->left;
    delete root->right;
    delete root;
    
    return 0;
}
