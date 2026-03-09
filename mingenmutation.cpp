//Minimum Genetic Mutation
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {

        unordered_set<string> st(bank.begin(), bank.end());

        if (st.find(endGene) == st.end())
            return -1;

        queue<string> q;
        q.push(startGene);

        int steps = 0;
        vector<char> genes = {'A','C','G','T'};

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                string curr = q.front();
                q.pop();

                if (curr == endGene)
                    return steps;

                for (int i = 0; i < curr.size(); i++) {

                    char original = curr[i];

                    for (char g : genes) {

                        curr[i] = g;

                        if (st.find(curr) != st.end()) {
                            q.push(curr);
                            st.erase(curr);
                        }
                    }

                    curr[i] = original;
                }
            }

            steps++;
        }

        return -1;
    }
};

int main() {

    Solution obj;

    string startGene = "AACCGGTT";
    string endGene = "AACCGGTA";

    vector<string> bank = {"AACCGGTA"};

    int result = obj.minMutation(startGene, endGene, bank);

    cout << result;

    return 0;
}