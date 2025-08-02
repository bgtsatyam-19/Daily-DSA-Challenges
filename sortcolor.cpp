#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low= 0;
        int mid= 0;
        int high=nums.size()-1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
int main(){
    Solution s;
    vector<int> nums={2,0,2,1,1,0};
    s.sortColors(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
}

//in this question we have to sort the array in such a way that all the 0s come first, then 1s and then 2s