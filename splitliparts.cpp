//Split Linked List in Parts
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k, nullptr);

        int length = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }

        int baseSize = length / k;
        int extra = length % k;

        ListNode* curr = head;

        for (int i = 0; i < k; i++) {
            result[i] = curr;

            int partSize = baseSize + (extra > 0 ? 1 : 0);
            if (extra > 0) extra--;

            for (int j = 1; j < partSize && curr != nullptr; j++) {
                curr = curr->next;
            }

            if (curr != nullptr) {
                ListNode* nextPart = curr->next;
                curr->next = nullptr;
                curr = nextPart;
            }
        }

        return result;
    }
};

int main() {
    return 0;
}
