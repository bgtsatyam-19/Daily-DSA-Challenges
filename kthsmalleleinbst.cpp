//Kth Smallest Element in a BST
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* current = root;

        while (current != nullptr || !st.empty()) {
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }

            current = st.top();
            st.pop();
            k--;

            if (k == 0) {
                return current->val;
            }

            current = current->right;
        }

        return -1; 
    }
};
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    Solution sol;
    int k = 2;
    int result = sol.kthSmallest(root, k);
    cout << "The " << k << "nd smallest element in the BST is: " << result << endl;

    return 0;
}
