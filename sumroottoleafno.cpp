//Sum Root to Leaf Numbers
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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
private:
    int dfs(TreeNode* node, int currentSum) {
        if (!node) return 0;
        
        currentSum = currentSum * 10 + node->val;
        
        if (!node->left && !node->right) {
            return currentSum; // Leaf node
        }
        
        return dfs(node->left, currentSum) + dfs(node->right, currentSum);
    }
};
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution solution;
    int result = solution.sumNumbers(root);
    cout << "Sum of root-to-leaf numbers: " << result << endl;

    function<void(TreeNode*)> deleteTree = [&](TreeNode* node) {
        if (!node) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    };
    deleteTree(root);

    return 0;
}