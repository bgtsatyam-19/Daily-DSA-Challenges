#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        if(intervals.empty()) return merged;
        sort(intervals.begin(), intervals.end());
        merged.push_back(intervals[0]);
        for(int i=0;i<intervals.size();++i){
            vector<int>& last = merged.back();
            if(intervals[i][0] <= last[1]){
                last[1] = max(last[1], intervals[i][1]);
            }
            else{
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};

int main(){
    Solution s;
    vector<vector<int>> intervals={{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans=s.merge(intervals);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}