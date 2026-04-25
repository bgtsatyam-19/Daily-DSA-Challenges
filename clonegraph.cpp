//Clone Graph
#include<bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    vector<Node*> neighbors;
    Node() : val(0), neighbors(vector<Node*>()) {}
    Node(int _val) : val(_val), neighbors(vector<Node*>()) {}
    Node(int _val, vector<Node*> _neighbors) : val(_val), neighbors(_neighbors) {}
};
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> visited;
        return dfs(node, visited);
    }
private:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& visited) {
        if (visited.count(node)) return visited[node];
        
        Node* clone = new Node(node->val);
        visited[node] = clone;
        
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbor, visited));
        }
        
        return clone;
    }
};
int main() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    Solution solution;
    Node* clonedGraph = solution.cloneGraph(node1);

    cout << "Cloned graph starting from node with value: " << clonedGraph->val << endl;

    function<void(Node*, unordered_set<Node*>&)> printGraph = [&](Node* node, unordered_set<Node*>& visited) {
        if (!node || visited.count(node)) return;
        visited.insert(node);
        cout << "Node " << node->val << " neighbors: ";
        for (Node* neighbor : node->neighbors) {
            cout << neighbor->val << " ";
        }
        cout << endl;
        for (Node* neighbor : node->neighbors) {
            printGraph(neighbor, visited);
        }
    };

    unordered_set<Node*> visited;
    printGraph(clonedGraph, visited);

    function<void(Node*, unordered_set<Node*>&)> deleteGraph = [&](Node* node, unordered_set<Node*>& visited) {
        if (!node || visited.count(node)) return;
        visited.insert(node);
        for (Node* neighbor : node->neighbors) {
            deleteGraph(neighbor, visited);
        }
        delete node;
    };

    visited.clear();
    deleteGraph(node1, visited);
    visited.clear();
    deleteGraph(clonedGraph, visited);

    return 0;
}
