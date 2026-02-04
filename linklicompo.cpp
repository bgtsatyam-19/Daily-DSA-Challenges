//Linked List Components
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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> nodeSet(G.begin(), G.end());
        int count = 0;
        bool inComponent = false;

        ListNode* current = head;
        while (current != nullptr) {
            if (nodeSet.find(current->val) != nodeSet.end()) {
                if (!inComponent) {
                    count++;
                    inComponent = true;
                }
            } else {
                inComponent = false;
            }
            current = current->next;
        }

        return count;
    }
};
int main() {
    return 0;
}