//Longest Absolute File Path
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthLongestPath(string input) {
        int maxLength = 0;
        unordered_map<int, int> pathLength;
        pathLength[0] = 0;

        stringstream ss(input);
        string line;
        while (getline(ss, line, '\n')) {
            int level = line.find_last_of('\t') + 1;
            string name = line.substr(level);

            if (name.find('.') != string::npos) {
                maxLength = max(maxLength, pathLength[level] + (int)name.length());
            } else {
                pathLength[level + 1] = pathLength[level] + name.length() + 1;
            }
        }
        return maxLength;
    }
};

int main() {
    Solution obj;
    string input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    cout << obj.lengthLongestPath(input) << endl;
    return 0;
}
