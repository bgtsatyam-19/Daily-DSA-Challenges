//Binary Tree Tilt
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
    int findTilt(TreeNode* root) {
        int total_tilt = 0;
        calculateTilt(root, total_tilt);
        return total_tilt;
    }
    int calculateTilt(TreeNode* node, int& total_tilt) {
        if (!node) return 0;
        
        int left_sum = calculateTilt(node->left, total_tilt);
        int right_sum = calculateTilt(node->right, total_tilt);
        
        int tilt = abs(left_sum - right_sum);
        total_tilt += tilt;
        
        return left_sum + right_sum + node->val;
    }
};
int main() {
    Solution solution;
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    int result = solution.findTilt(root);
    cout << "Total tilt of the binary tree: " << result << endl;
    
    // Clean up memory
    delete root->left;
    delete root->right;
    delete root;
    
    return 0;
}
