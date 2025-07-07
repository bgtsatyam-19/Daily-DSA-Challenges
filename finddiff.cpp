#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
      char result=0;
      for(char ch : s)
      result ^=ch;
      for(char ch : t) 
      result ^=ch;

      return result; 
    }
};
int main()
{
    Solution s;
    cout<<s.findTheDifference("abcd","abcde")<<endl;
    return 0;
}
