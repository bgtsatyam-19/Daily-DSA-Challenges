
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        if(n==1) return 1;
        int index=0;
        for(int i=0;i<n;){
            char current_char=chars[i];
            int count=0;
            while(i<n && chars[i]==current_char){
                count++;
                i++;
            }
            chars[index++]=current_char;
            if(count>1){
                string cnt=to_string(count);
                for(char c:cnt){
                    chars[index++]=c;
                }
            }
        }
        return index;
    }
};
int main(){
    Solution obj;
    vector<char> chars={'a','a','b','b','c','c','c'};
    int ans=obj.compress(chars);
    cout<<ans<<endl;
    for(int i=0;i<ans;i++){
        cout<<chars[i]<<" ";
    }
    return 0;
}