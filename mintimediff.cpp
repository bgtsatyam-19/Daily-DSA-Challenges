//Minimum Time Difference
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutesList;
        for (const string& time : timePoints) {
            int hours = stoi(time.substr(0, 2));
            int minutes = stoi(time.substr(3, 2));
            minutesList.push_back(hours * 60 + minutes);
        }
        sort(minutesList.begin(), minutesList.end());
        int minDiff = INT_MAX;
        for (size_t i = 1; i < minutesList.size(); ++i) {
            minDiff = min(minDiff, minutesList[i] - minutesList[i - 1]);
        }
        minDiff = min(minDiff, 1440 - (minutesList.back() - minutesList.front()));
        return minDiff;
    }
};  
int main(){
    Solution obj;
    vector<string> timePoints={"23:59","00:00"};
    cout<<obj.findMinDifference(timePoints)<<endl; 
    return 0;
}