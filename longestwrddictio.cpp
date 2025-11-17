//Longest Word in Dictionary through Deleting
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSubsequence(const string& s, const string& target) {
        int sIndex = 0, tIndex = 0;
        while (sIndex < s.size() && tIndex < target.size()) {
            if (s[sIndex] == target[tIndex]) {
                sIndex++;
            }
            tIndex++;
        }
        return sIndex == s.size();
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        string longestWord = "";
        for (const string& word : dictionary) {
            if (isSubsequence(word, s)) {
                if (word.size() > longestWord.size() || 
                    (word.size() == longestWord.size() && word < longestWord)) {
                    longestWord = word;
                }
            }
        }
        return longestWord;
    }
};
int main(){
    Solution obj;
    string s="abpcplea";
    vector<string> dictionary={"ale","apple","monkey","plea"};
    cout<<obj.findLongestWord(s,dictionary)<<endl; 
    return 0;
}