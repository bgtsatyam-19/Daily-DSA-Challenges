//Linked List Random Node
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {

    public:
    vector<int> values;

    Solution(ListNode* head) {
        while (head) {
            values.push_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom() {
        int randomIndex = rand() % values.size();
        return values[randomIndex];
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
            tail = tail->next;
        }
    }

    Solution sol(head);
    int q;
    cin >> q; // number of random queries
    for (int i = 0; i < q; ++i) {
        cout << sol.getRandom() << endl;
    }

    return 0;
}
