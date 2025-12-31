//reversed linked list
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current) {
            ListNode* nextTemp = current->next; 
            current->next = prev;             
            prev = current;                   
            current = nextTemp;               
        }
        return prev; 
    }
};      
int main(){
    Solution obj;
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode* result = obj.reverseList(head);
    while (result) {
        cout << result->val << " "; 
        result = result->next;
    }
    cout << endl;
    return 0;
}