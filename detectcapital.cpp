//Detect Capital
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.size();
        if(n==1) return true;
        if(isupper(word[0]) && isupper(word[1])){
            for(int i=2;i<n;i++){
                if(islower(word[i])) return false;
            }
        }
        else if(isupper(word[0]) && islower(word[1])){
            for(int i=2;i<n;i++){
                if(isupper(word[i])) return false;
            }
        }
        else{
            for(int i=1;i<n;i++){
                if(isupper(word[i])) return false;
            }
        }
        return true;
    }
};
int main(){
    Solution obj;
    string word="FlaG";
    bool ans=obj.detectCapitalUse(word);
    cout<<ans<<endl;
    return 0;
}