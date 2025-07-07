#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        for(int h=0;h<12;++h){
            for(int m=0;m<60;++m){
                int bitson= __builtin_popcount(h)+__builtin_popcount(m);
                if(bitson == turnedOn){
                    char buffer[6];
                    sprintf(buffer , "%d:%02d",h,m);
                    result.push_back(buffer);
                }
            }
        }
        return result;
    }
};
int main(){
    Solution s;
    vector<string> ans=s.readBinaryWatch(1);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}