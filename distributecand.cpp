//Distribute Candies
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> uniqueTypes(candyType.begin(), candyType.end());
        return min(uniqueTypes.size(), candyType.size() / 2);
    }
};
int main() {
    Solution solution;
    vector<int> candyType = {1, 1, 2, 2, 3, 3};
    int result = solution.distributeCandies(candyType);
    cout << "Maximum number of different types of candies Alice can eat: " << result << endl;
    return 0;
}
