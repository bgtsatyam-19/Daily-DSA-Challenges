#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[i - 1][1]) {
                return false;  // overlap detected
            }
        }

        return true;
    }
};
int main(){
    Solution s;
    vector<vector<int>> intervals={{0,30},{5,10},{15,20}};
    cout<<boolalpha<<s.canAttendMeetings(intervals)<<endl;
    return 0;

}