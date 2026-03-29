//Subtree of Another Tree
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

    // Function to check if two trees are identical
    bool isSame(TreeNode* a, TreeNode* b) {
        
        // If both are NULL → identical
        if (a == NULL && b == NULL) return true;

        // If one is NULL → not identical
        if (a == NULL || b == NULL) return false;

        // Check value and recursively check left & right
        return (a->val == b->val) &&
               isSame(a->left, b->left) &&
               isSame(a->right, b->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        // If root is NULL → no subtree possible
        if (root == NULL) return false;

        // Check if current subtree matches
        if (isSame(root, subRoot)) return true;

        // Otherwise check in left or right subtree
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};
int main() {
    Solution solution;
    // Example usage:
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    bool result = solution.isSubtree(root, subRoot);
    cout << "Is subRoot a subtree of root? " << (result ? "Yes" : "No") << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    delete subRoot->left;
    delete subRoot->right;
    delete subRoot;

    return 0;
}
