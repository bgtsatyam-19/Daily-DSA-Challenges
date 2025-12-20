//Palindrome Pairs
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        unordered_map<string, int> wordMap;
        for (int i = 0; i < words.size(); ++i) {
            wordMap[words[i]] = i;
        }

        for (int i = 0; i < words.size(); ++i) {
            const string& word = words[i];
            for (int j = 0; j <= word.size(); ++j) {
                string prefix = word.substr(0, j);
                string suffix = word.substr(j);

                if (isPalindrome(suffix)) {
                    string revPrefix = prefix;
                    reverse(revPrefix.begin(), revPrefix.end());
                    if (wordMap.count(revPrefix) && wordMap[revPrefix] != i) {
                        result.push_back({i, wordMap[revPrefix]});
                    }
                }

                if (j > 0 && isPalindrome(prefix)) {
                    string revSuffix = suffix;
                    reverse(revSuffix.begin(), revSuffix.end());
                    if (wordMap.count(revSuffix) && wordMap[revSuffix] != i) {
                        result.push_back({wordMap[revSuffix], i});
                    }
                }
            }
        }
        return result;
    }

private:
    bool isPalindrome(const string& str) {
        int left = 0, right = str.size() - 1;
        while (left < right) {
            if (str[left++] != str[right--]) {
                return false;
            }
        }
        return true;
    }
};
int main(){
    Solution obj;
    vector<string> words={"bat","tab","cat"};
    vector<vector<int>> result=obj.palindromePairs(words);
    for(const auto& pair:result){
        cout<<"["<<pair[0]<<","<<pair[1]<<"]"<<endl; //Output: [0,1] [1,0]
    }
    return 0;
}
