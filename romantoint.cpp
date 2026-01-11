//roman to int
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int total = 0;
        int prevValue = 0;
        
        for(char c : s) {
            int currValue = romanMap[c];
            if(currValue > prevValue) {
                total += currValue - 2 * prevValue;
            } else {
                total += currValue;
            }
            prevValue = currValue;
        }
        
        return total;
    }
};
int main() {
    string s;
    cin >> s;
    
    Solution obj;
    int result = obj.romanToInt(s);
    
    cout << result << endl;
    
    return 0;
}
