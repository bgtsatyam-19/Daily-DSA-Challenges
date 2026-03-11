//Find Duplicate File in System
#include <iostream>
#include <vector>
#include <unordered_map>
#include<queue>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {

        unordered_map<string, vector<string>> m;

        for (auto path : paths) {

            string curr = "";
            string file = "";
            string content = "";
            int i = 0;

            while (i < path.size() && path[i] != ' ') {
                curr += path[i];
                i++;
            }

            i++;

            while (i < path.size()) {

                while (i < path.size() && path[i] != ' ') {
                    file += path[i];
                    i++;
                }

                int j = file.size() - 1;

                while (j >= 0 && file[j] != '(') {
                    content += file[j];
                    j--;
                }

                reverse(content.begin(), content.end());
                file = file.substr(0, j);

                m[content].push_back(curr + "/" + file);
                content = "";
                file = "";

                i++;
            }
        }

        vector<vector<string>> ans;

        for (auto it : m) {
            if (it.second.size() > 1)
                ans.push_back(it.second);
        }

        return ans;
    }
};
int main() {

    Solution obj;

    vector<string> paths = {"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"};

    vector<vector<string>> ans = obj.findDuplicate(paths);

    for (auto i : ans) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
