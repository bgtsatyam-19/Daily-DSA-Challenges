//N-ary Tree Preorder Traversal
#include<bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        if (root == nullptr) return result;

        // Helper function for DFS
        function<void(Node*)> dfs = [&](Node* node) {
            if (node == nullptr) return;
            result.push_back(node->val); // Process current node
            for (Node* child : node->children) {
                dfs(child); // Recur for each child
            }
        };

        dfs(root); // Start DFS from the root
        return result;
    }
};
int main() {
    Solution solution;
    // Example usage:
    Node* root = new Node(1);
    root->children.push_back(new Node(3));
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(4));
    root->children[0]->children.push_back(new Node(5));
    root->children[0]->children.push_back(new Node(6));

    vector<int> result = solution.preorder(root);
    cout << "Preorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory
    delete root->children[0]->children[0];
    delete root->children[0]->children[1];
    delete root->children[0];
    delete root->children[1];
    delete root->children[2];
    delete root;
    
    return 0;
}
