//Reverse Words in a String
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;
        
        while (ss >> word) {
            words.push_back(word);
        }
        
        reverse(words.begin(), words.end());
        
        string result;
        for (size_t i = 0; i < words.size(); ++i) {
            result += words[i];
            if (i != words.size() - 1) {
                result += " ";
            }
        }
        
        return result;
    }
};
int main(){
    Solution obj;
    string s="the sky is blue";
    string result=obj.reverseWords(s);
    cout<<result<<endl; 
    return 0;
}