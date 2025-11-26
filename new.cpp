//find lluckey integer in an array
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }

        int luckyInteger = -1;
        for (const auto& entry : freq) {
            if (entry.first == entry.second) {
                luckyInteger = max(luckyInteger, entry.first);
            }
        }
        return luckyInteger;
    }
};
int main(){
    Solution obj;
    vector<int> arr={2,2,3,4};
    cout<<obj.findLucky(arr)<<endl; 
    return 0;
}
