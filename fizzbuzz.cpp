#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> fizzBuzz(int n) {
   vector<string> result;
   for(int i =1;i<=n;i++){
    if(i%3 == 0 && i%5 == 0){
    result.push_back("FizzBuzz");
    }
    else if(i%3==0){
        result.push_back("Fizz");
    }
    else if(i%5==0){
        result.push_back("Buzz");
    }
    else{
    result.push_back(to_string(i));
   }     }  
   return result;
    }
};
int main(){
    Solution s;
    vector<string> ans=s.fizzBuzz(15);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
    return 0;
}