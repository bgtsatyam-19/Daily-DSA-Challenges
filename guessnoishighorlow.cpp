//Guess Number Higher or Lower
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int guess(int num) {

    int target = 6; 
    if (num < target) return 1;
    else if (num > target) return -1;
    else return 0;
}
    int guessNumber(int n) {
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int res = guess(mid);
            if (res == 0) {
                return mid; 
            } else if (res < 0) {
                right = mid - 1; 
            } else {
                left = mid + 1; 
            }
        }
        return -1; 
    }
};
int main() {
    Solution solution;
    int n = 10;
    int result = solution.guessNumber(n);
    cout << "The guessed number is: " << result << endl;
    return 0;
}
