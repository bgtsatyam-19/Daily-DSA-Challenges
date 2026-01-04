//Remove Nth Node From End of List
#include <bits/stdc++.h>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = dummy;
        ListNode* second = dummy;

        for (int i = 0; i <= n; ++i) {
            first = first->next;
        }

        while (first) {
            first = first->next;
            second = second->next;
        }

        ListNode* nodeToDelete = second->next;
        second->next = second->next->next;
        delete nodeToDelete;

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
int main(){
    Solution obj;
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    int n = 2;
    ListNode* result = obj.removeNthFromEnd(head, n);
    while (result) {
        cout << result->val << " "; 
        result = result->next;
    }
    cout << endl;
    return 0;
}
