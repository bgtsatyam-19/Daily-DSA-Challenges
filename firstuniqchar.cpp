//First Unique Character in a String
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);

        for(char c : s){
            freq[c - 'a']++;
        }

        for(int i = 0; i < s.size(); i++){
            if(freq[s[i] - 'a'] == 1){
                return i;  
            }
        }

        return -1;
    }
};
int main() {
    Solution obj;
    string s;
    cout << "Enter a string: ";
    getline(cin, s);  

    int index = obj.firstUniqChar(s);
    if(index != -1){
        cout << "The index of the first unique character is: " << index << endl;
    } else {
        cout << "No unique character found." << endl;
    }
    return 0;
}