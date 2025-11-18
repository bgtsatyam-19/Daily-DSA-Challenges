#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {

        auto parseComplex = [](const string& num) {
            int plusPos = num.find('+');
            int realPart = stoi(num.substr(0, plusPos));
            int imagPart = stoi(num.substr(plusPos + 1, num.size() - plusPos - 2));
            return make_pair(realPart, imagPart);
        };

        auto [a, b] = parseComplex(num1);
        auto [c, d] = parseComplex(num2);

        int realResult = a * c - b * d;
        int imagResult = a * d + b * c;

        return to_string(realResult) + "+" + to_string(imagResult) + "i";
    }
};

int main(){
    Solution obj;
    string num1="1+1i";
    string num2="1+1i";
    cout<<obj.complexNumberMultiply(num1,num2)<<endl;
    return 0;
}
