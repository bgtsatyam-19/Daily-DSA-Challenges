// remove duplicates from sorted linked list

#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        
        ListNode* current = head;
        
        while (current && current->next) {
            if (current->val == current->next->val) {
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp; // Free memory
            } else {
                current = current->next;
            }
        }
        
        return head;
    }
};
int main() {
    int n;
    cin >> n;
    
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
    head = obj.deleteDuplicates(head);
    
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
