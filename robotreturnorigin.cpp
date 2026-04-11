//Robot Return to Origin
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (char move : moves) {
            if (move == 'U') y++;
            else if (move == 'D') y--;
            else if (move == 'L') x--;
            else if (move == 'R') x++;
        }
        return x == 0 && y == 0;
    }
};
int main() {
    Solution solution;
    string moves = "UDLR";
    bool result = solution.judgeCircle(moves);
    cout << "Robot returns to origin: " << (result ? "Yes" : "No") << endl;

    return 0;
}
