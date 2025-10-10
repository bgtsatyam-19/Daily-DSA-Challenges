//License Key Formatting
#include<bits/stdc++.h>
using namespace std;
class solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string str="";
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]!='-'){
                str+=toupper(s[i]);
            }
        }
        string res="";
        int count=0;
        for(int i=0;i<str.length();i++){
            if(count==k){
                res+='-';
                count=0;
            }
            res+=str[i];
            count++;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
int main(){
    solution obj;
    string s="2-4A0r7-4k";
    int k=4;
    string ans=obj.licenseKeyFormatting(s,k);
    cout<<ans<<endl;
    return 0;
}