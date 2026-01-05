//copy-list-with-random-pointer
#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        Node* curr = head;
        while (curr) {
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        curr = head;
        Node* newHead = head->next;
        Node* copyCurr = newHead;

        while (curr) {
            curr->next = curr->next->next;
            if (copyCurr->next) {
                copyCurr->next = copyCurr->next->next;
            }
            curr = curr->next;
            copyCurr = copyCurr->next;
        }

        return newHead;
    }
};
int main() {
    Solution obj;
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);

    head->random = nullptr;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;

    Node* copiedList = obj.copyRandomList(head);

    Node* curr = copiedList;
    while (curr) {
        cout << "Node val: " << curr->val << ", Random val: ";
        if (curr->random) {
            cout << curr->random->val << endl;
        } else {
            cout << "nullptr" << endl;
        }
        curr = curr->next;
    }

    return 0;
}
