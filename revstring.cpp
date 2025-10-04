//Reverse String
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseString(string s) {
  int i = 0, j = s.length() - 1;      
    while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
    }
};
int main(){
   Solution obj;
    string s;
    cout << "Enter a string: ";
    getline(cin, s);  

    string reversed = obj.reverseString(s);
    cout << "Reversed string: " << reversed << endl;

    return 0;
}