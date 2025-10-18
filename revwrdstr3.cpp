//Reverse Words in a String III
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string result;
        while(ss>>word){
            reverse(word.begin(),word.end());
            result+=word+" ";
        }
        result.pop_back(); // Remove the trailing space
        return result;
    }
};
int main(){
    Solution obj;
    string s="Let's take LeetCode contest";
    cout<<obj.reverseWords(s)<<endl;
    return 0;
}