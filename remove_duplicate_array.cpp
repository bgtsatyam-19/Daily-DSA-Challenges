#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
  
    unordered_set<int> s; 
  
    int idx = 0;  

    for (int i = 0; i < nums.size(); i++) {
        if (s.find(nums[i]) == s.end()) { 
            s.insert(nums[i]);  
            nums[idx++] = nums[i];  
        }
    }
    return s.size(); 
}

int main() {
    vector<int> nums = {1, 2, 2, 3, 4, 4, 4, 5, 5};
    int newSize = removeDuplicates(nums);
    for (int i = 0; i < newSize; i++) 
        cout << nums[i] << " ";
    return 0;
}