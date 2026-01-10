//remove linked list from elements
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head != NULL && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        ListNode* current = head;
        while(current != NULL && current->next != NULL) {
            if(current->next->val == val) {
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
        return head;
    }
};
   int main() {
    int n, val;
    cin >> n >> val;

    int x;
    cin >> x;
    ListNode* head = new ListNode(x);
    ListNode* temp = head;

    for(int i = 1; i < n; i++) {
        cin >> x;
        temp->next = new ListNode(x);
        temp = temp->next;
    }

    Solution obj;
    head = obj.removeElements(head, val);

    temp = head;
    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}