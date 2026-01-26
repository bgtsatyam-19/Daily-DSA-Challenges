//Reverse Linked List II
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }

        ListNode* const reverseStart = prev->next;
        ListNode* curr = reverseStart->next;

        for (int i = 0; i < right - left; ++i) {
            reverseStart->next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
            curr = reverseStart->next;
        }

        return dummy.next;
    }
};
int main() {
    int n, left, right;
    cin >> n;
    ListNode* head = NULL;
    ListNode* tail = NULL;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        ListNode* newNode = new ListNode(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    cin >> left >> right;

    Solution obj;
    ListNode* newHead = obj.reverseBetween(head, left, right);

    ListNode* current = newHead;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    return 0;
}