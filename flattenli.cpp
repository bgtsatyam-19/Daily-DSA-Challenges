//Flatten a Multilevel Doubly Linked List
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node(int x) : val(x), prev(NULL), next(NULL), child(NULL) {}
};
class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;

        Node* curr = head;
        stack<Node*> stk;

        while (curr) {
            if (curr->child) {
                if (curr->next) {
                    stk.push(curr->next);
                }
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;
            }
            if (!curr->next && !stk.empty()) {
                Node* nextNode = stk.top();
                stk.pop();
                curr->next = nextNode;
                nextNode->prev = curr;
            }
            curr = curr->next;
        }

        return head;
    }
};
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->child = new Node(3);
    head->next->child->next = new Node(4);
    head->next->child->next->prev = head->next->child;

    Solution sol;
    Node* flatHead = sol.flatten(head);

    Node* curr = flatHead;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}
