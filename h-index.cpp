#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        sort(citations.begin(),citations.end());
        int h=0;
        for(int i=n-1;i>=0;i--)
        {
            if(citations[i]>h)
            {
                h++;
            }
        }
        return h;
    }  
};
int main(){
    Solution sol;
    vector<int> citations={0,1,3,5,6};
    cout<<sol.hIndex(citations)<<endl;
    return 0;
}