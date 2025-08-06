#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int n = gas.size();
            int total = 0;
            int sum = 0;
            int start = 0;
            for(int i = 0; i < n; i++){
                total += gas[i] - cost[i];
                sum += gas[i] - cost[i];
                if(sum < 0){
                    sum = 0;
                    start = i + 1;
                }
            }
            return total >= 0 ? start : -1;
        }
};
int main(){
    Solution s;
    vector<int> gas={1,2,3,4,5};
    vector<int> cost={3,4,5,1,2};
    cout<<s.canCompleteCircuit(gas,cost);
}