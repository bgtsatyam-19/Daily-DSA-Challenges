//linked list cycle
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;           
            fast = fast->next->next;     

            if (slow == fast) {
                return true; 
            }
        }
        return false; 
    }
};
int main(){
    Solution obj;
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; 

    bool result = obj.hasCycle(head);
    cout << (result ? "true" : "false") << endl; //Output: true
    return 0;
}
