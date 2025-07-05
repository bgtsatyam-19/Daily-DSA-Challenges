#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1(nums1.begin(),nums1.end());
    unordered_set<int>result;
    for(int num :nums2){
        if(set1.count(num)){
            result.insert(num);
        }
    }
    return vector<int>(result.begin(),result.end());
    }
};
int main(){
    Solution s;
    vector<int> nums1={1,2,2,1};
    vector<int> nums2={2,2};
    vector<int> ans=s.intersection(nums1,nums2);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}