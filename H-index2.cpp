#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int h = 0;
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= i+1) {
                h = i+1;
            } else {
                break;
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