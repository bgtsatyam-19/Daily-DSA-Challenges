//Intersection of Two Linked Lists

#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        ListNode* a = headA;
        ListNode* b = headB;
        while(a != b) {
            a = (a == NULL) ? headB : a->next;
            b = (b == NULL) ? headA : b->next;
        }
        return a;
    }
};
int main() {
    int n1, n2, inter;
    cin >> n1 >> n2 >> inter;

    int x;
    cin >> x;
    ListNode* headA = new ListNode(x);
    ListNode* tempA = headA;

    for(int i = 1; i < n1; i++) {
        cin >> x;
        tempA->next = new ListNode(x);
        tempA = tempA->next;
    }

    cin >> x;
    ListNode* headB = new ListNode(x);
    ListNode* tempB = headB;

    for(int i = 1; i < n2; i++) {
        cin >> x;
        tempB->next = new ListNode(x);
        tempB = tempB->next;
    }

    if(inter > 0) {
        ListNode* interNode = headA;
        for(int i = 1; i < inter; i++) {
            interNode = interNode->next;
        }
        tempB->next = interNode;
    }

    Solution obj;
    ListNode* intersection = obj.getIntersectionNode(headA, headB);

    if(intersection != NULL) {
        cout << intersection->val << endl;
    } else {
        cout << "No intersection" << endl;
    }

    return 0;
}
