
#include<vector>
#include<iostream>
#include<cmath>
#include <climits>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int minprice=INT_MAX;
     int maxprofit=0;
     for(int price : prices){
        minprice=min(minprice,price);
        maxprofit=max(maxprofit,price-minprice);

     }   
     return maxprofit;
    }
};
int main(){
    Solution s;
    vector<int> prices={7,1,5,3,6,4};
    cout<<s.maxProfit(prices)<<endl;
    return 0;
}