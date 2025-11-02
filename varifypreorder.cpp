//Verify Preorder Serialization of a Binary Tree
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slots = 1; 
        stringstream ss(preorder);
        string node;
        
        while (getline(ss, node, ',')) {
            slots--; 
            if (slots < 0) return false; 
            if (node != "#") {
                slots += 2; 
            }
        }
        return slots == 0; 
    }
};
int main(){
    Solution obj;
    string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    cout << (obj.isValidSerialization(preorder) ? "true" : "false") << endl; // Output: true
    return 0;
}