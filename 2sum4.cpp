//Two Sum IV - Input is a BST
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
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        unordered_set<int> seen;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (seen.count(k - node->val)) {
                return true;
            }
            seen.insert(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        return false;
    }
};
int main() {
    Solution solution;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    int target = 9;
    bool result = solution.findTarget(root, target);
    cout << "Two sum exists in the BST: " << (result ? "Yes" : "No") << endl;

    return 0;
}
