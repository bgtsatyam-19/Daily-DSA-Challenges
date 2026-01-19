//pascals triangle 2
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        row.push_back(1);

        for (int i = 1; i <= rowIndex; i++) {
            for (int j = i - 1; j > 0; j--) {
                row[j] = row[j] + row[j - 1];
            }
            row.push_back(1);
        }
        return row;
    }
};

int main() {
    int rowIndex;
    cin >> rowIndex;

    Solution obj;
    vector<int> result = obj.getRow(rowIndex);

    for (int x : result) {
        cout << x << " ";
    }
    return 0;
}
