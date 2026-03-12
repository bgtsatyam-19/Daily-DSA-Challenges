//Task Scheduler
#include <iostream>
#include <vector>
#include <unordered_map>
#include<queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> m;

        for (auto task : tasks)
            m[task]++;

        priority_queue<int> pq;

        for (auto it : m)
            pq.push(it.second);

        int time = 0;

        while (!pq.empty()) {

            vector<int> temp;

            for (int i = 0; i < n + 1; i++) {

                if (!pq.empty()) {
                    temp.push_back(pq.top());
                    pq.pop();
                }
            }

            for (auto it : temp) {
                if (--it > 0)
                    pq.push(it);
            }

            time += pq.empty() ? temp.size() : n + 1;
        }

        return time;
    }
};
int main() {

    Solution s;
    vector<char> tasks = { 'A', 'A', 'A', 'B', 'B', 'B' };
    int n = 2;

    cout << s.leastInterval(tasks, n);

    return 0;
}

