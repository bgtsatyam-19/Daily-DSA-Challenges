//Path Sum II
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, targetSum, path, res);
        return res;
    }
private:
    void dfs(TreeNode* node, int targetSum, vector<int>& path, vector<vector<int>>& res) {
        if (!node) return;
        
        path.push_back(node->val);
        targetSum -= node->val;
        
        if (!node->left && !node->right && targetSum == 0) {
            res.push_back(path);
        }
        
        dfs(node->left, targetSum, path, res);
        dfs(node->right, targetSum, path, res);
        
        path.pop_back();
    }
};
int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;
    
    Solution solution;
    vector<vector<int>> result = solution.pathSum(root, targetSum);
    
    cout << "Paths that sum to " << targetSum << ":" << endl;
    for (const auto& path : result) {
        for (int num : path) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    // Clean up memory (delete nodes)
    function<void(TreeNode*)> deleteTree = [&](TreeNode* node) {
        if (!node) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    };
    
    deleteTree(root);
    
    return 0;
}
