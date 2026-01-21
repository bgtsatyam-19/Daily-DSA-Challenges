// Remove Duplicates from Sorted List II
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy; 
        ListNode* curr = head;   

        while (curr) {
            bool isDuplicate = false;
            while (curr->next && curr->val == curr->next->val) {
                isDuplicate = true;
                curr = curr->next; 
            }

            if (isDuplicate) {
                prev->next = curr->next; 
            } else {
                prev = prev->next; 
            }
            curr = curr->next; 
        }

        return dummy->next;
    }
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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
    ListNode* result = obj.deleteDuplicates(head);

    ListNode* curr = result;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}
