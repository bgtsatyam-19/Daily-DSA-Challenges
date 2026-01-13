//Rotate List
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;
        
        // Compute the length of the list and get the tail node
        ListNode* tail = head;
        int length = 1;
        while (tail->next) {
            tail = tail->next;
            length++;
        }
        
        // Make the list circular
        tail->next = head;
        
        // Find the new tail: (length - k % length - 1)th node
        // and the new head: (length - k % length)th node
        k = k % length;
        ListNode* newTail = head;
        for (int i = 0; i < length - k - 1; i++) {
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        
        // Break the circle
        newTail->next = nullptr;
        
        return newHead;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    Solution obj;
    head = obj.rotateRight(head, k);
    
    ListNode* current = head;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
    
    // Free memory
    current = head;
    while (current) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
    
    return 0;
}
