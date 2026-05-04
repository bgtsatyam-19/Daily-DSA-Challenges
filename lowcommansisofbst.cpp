//Lowest Common Ancestor of a Binary Tree
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left != nullptr && right != nullptr) {
            return root;
        }

        return left != nullptr ? left : right;
    }
};
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    Solution sol;
    TreeNode* p = root->left; // Node with value 5
    TreeNode* q = root->right; // Node with value 1
    TreeNode* result = sol.lowestCommonAncestor(root, p, q);
    
    if (result != nullptr) {
        cout << "The lowest common ancestor of " << p->val << " and " << q->val << " is: " << result->val << endl;
    } else {
        cout << "No common ancestor found." << endl;
    }

    return 0;
}
