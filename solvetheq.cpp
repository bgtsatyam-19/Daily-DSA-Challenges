//Solve the Equation
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string solveEquation(string equation) {
        int xCoeff = 0;  
        int constant = 0; 
        int sign = 1;    
        int i = 0;
        int n = equation.size();
        bool leftSide = true; 

        while (i < n) {
            if (equation[i] == '=') {
                leftSide = false;
                sign = 1; 
                i++;
                continue;
            }

            if (equation[i] == '+') {
                sign = 1;
                i++;
            } else if (equation[i] == '-') {
                sign = -1;
                i++;
            }

            int num = 0;
            bool isNumber = false;
            while (i < n && isdigit(equation[i])) {
                num = num * 10 + (equation[i] - '0');
                i++;
                isNumber = true;
            }

            if (i < n && equation[i] == 'x') {
                if (!isNumber) num = 1; 
                xCoeff += (leftSide ? sign * num : -sign * num);
                i++; 
            } else {
                constant += (leftSide ? -sign * num : sign * num);
            }
        }

        if (xCoeff == 0) {
            return constant == 0 ? "Infinite solutions" : "No solution";
        } else {
            int xValue = constant / xCoeff;
            return "x=" + to_string(xValue);
        }
    }
};
int main(){
    Solution obj;
    string equation="x+5-3+x=6+x-2";
    cout<<obj.solveEquation(equation)<<endl;
    return 0;
}