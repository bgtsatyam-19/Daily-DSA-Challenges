//Simplify Path
#include<bits/stdc++.h> 
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string token;
        
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            } else if (token == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                stack.push_back(token);
            }
        }
        
        string simplifiedPath = "/";
        for (size_t i = 0; i < stack.size(); ++i) {
            simplifiedPath += stack[i];
            if (i != stack.size() - 1) {
                simplifiedPath += "/";
            }
        }
        
        return simplifiedPath;
    }
};
int main(){
    Solution obj;
    string path="/a/./b/../../c/";
    string result=obj.simplifyPath(path);
    cout<<result<<endl; 
    return 0;
}