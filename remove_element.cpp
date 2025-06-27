#include<bits/stdc++.h>
using namespace std;
int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int k=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=val){
                nums[k++]=nums[i];
            }
        }
        return k;
    }
    int main(){
        vector<int> nums={3,2,2,3};
        int val=3;
        int n=removeElement(nums,val);
        for(int i=0;i<n;i++){
            cout<<nums[i]<<" ";
        }
        return 0;
    }
    //this code is to remove the elements from the vector
    //time complexity is O(n)
    //space complexity is O(1)