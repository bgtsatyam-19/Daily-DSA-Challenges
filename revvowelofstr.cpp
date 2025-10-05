//Reverse Vowels of a String
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        while (i < j) {
            while (i < j && vowels.find(s[i]) == vowels.end()) i++;
            while (i < j && vowels.find(s[j]) == vowels.end()) j--;
            if (i < j) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
    }
};
int main(){
   Solution obj;
    string s;
    cout << "Enter a string: ";
    getline(cin, s);  

    string result = obj.reverseVowels(s);
    cout << "String after reversing vowels: " << result << endl;
    return 0;
}