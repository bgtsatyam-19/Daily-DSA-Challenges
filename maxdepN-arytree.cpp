//Maximum Depth of N-ary Tree
#include<bits/stdc++.h>
using namespace std;
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
    int maxDepth(Node* root) {
        if (!root) return 0;
        
        int max_depth = 0;
        for (Node* child : root->children) {
            max_depth = max(max_depth, maxDepth(child));
        }
        
        return max_depth + 1;
    }
};
int main() {
    Solution solution;
    // Example usage:
    Node* root = new Node(1);
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(3));
    root->children[0]->children.push_back(new Node(4));
    root->children[0]->children.push_back(new Node(5));
    
    int result = solution.maxDepth(root);
    cout << "Maximum depth of the N-ary tree: " << result << endl;
    
    // Clean up memory
    delete root->children[0]->children[0];
    delete root->children[0]->children[1];
    delete root->children[0];
    delete root->children[1];
    delete root;
    
    return 0;
}
