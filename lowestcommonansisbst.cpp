//Lowest Common Ancestor of a Binary Search Tree
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
        if (root == nullptr) {
            return nullptr;
        }

        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        return root;
    }
};
int main() {
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    Solution sol;
    TreeNode* p = root->left; // Node with value 2
    TreeNode* q = root->right; // Node with value 8
    TreeNode* result = sol.lowestCommonAncestor(root, p, q);
    
    if (result != nullptr) {
        cout << "The lowest common ancestor of " << p->val << " and " << q->val << " is: " << result->val << endl;
    } else {
        cout << "No common ancestor found." << endl;
    }

    return 0;
}
