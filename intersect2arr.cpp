#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
      unordered_map<int ,int>freq;
      vector<int>result;
      for(int num:nums1){
        freq[num]++;
      }  
      for(int num:nums2){
        if(freq[num]>0){
            result.push_back(num);
            freq[num]--;
        }
      }
      return result;
    }
};
int main(){
    Solution s;
    vector<int> nums1={1,2,2,1};
    vector<int> nums2={2,2};
    vector<int> ans=s.intersect(nums1,nums2);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}