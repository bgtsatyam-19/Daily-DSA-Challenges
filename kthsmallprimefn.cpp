//K-th Smallest Prime Fraction
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int K) {
        int n = arr.size();
        auto compare = [&](const pair<int, int>& a, const pair<int, int>& b) {
            return arr[a.first] * arr[b.second] > arr[b.first] * arr[a.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> minHeap(compare);

        for (int i = 0; i < n - 1; ++i) {
            minHeap.push({i, n - 1});
        }

        for (int i = 0; i < K - 1; ++i) {
            pair<int, int> p = minHeap.top();
            minHeap.pop();
            if (p.second - 1 > p.first) {
                minHeap.push({p.first, p.second - 1});
            }
        }

        pair<int, int> result_pair = minHeap.top();
        return {arr[result_pair.first], arr[result_pair.second]};
    }
};
int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 5};
    int K = 3;
    vector<int> result = sol.kthSmallestPrimeFraction(arr, K);
    cout << "K-th Smallest Prime Fraction: " << result[0] << "/" << result[1] << endl;
    return 0;
}
