#include <iostream>
#include <vector>
#include <unordered_set>
#include <cctype>  
using namespace std;
 class Solution {
public:
    vector<string> findWords(vector<string>& words) {
      string row1 = "qwertyuiop";
      string row2 = "asdfghjkl";
      string row3 = "zxcvbnm";

       unordered_set<char> set1(row1.begin(),row1.end());
       unordered_set<char> set2(row2.begin(),row2.end());
       unordered_set<char> set3(row3.begin(),row3.end());
       vector<string> result;

       for(const string& word:words){
        if(word.empty())continue;
        char firstchar = tolower(word[0]);
        unordered_set<char>* currentset =nullptr;

        if(set1.count(firstchar)) currentset = &set1;
        else if(set2.count(firstchar)) currentset = &set2;
        else if(set3.count(firstchar)) currentset = &set3;
        bool valid =true;
        for(char ch : word)
        {
            if(!currentset->count(tolower(ch)))
            {
                valid = false;
                break;
            }
        }
        if(valid) result.push_back(word);            
           }  
    
    return result;
}
};
int main(){
    Solution s;
    vector<string> words={"Hello","Alaska","Dad","Peace"};
    vector<string> result = s.findWords(words);
    for(string word : result){
        cout<<word<<endl;
    }
}