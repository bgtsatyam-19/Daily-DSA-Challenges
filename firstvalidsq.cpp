//Valid Perfect Square
#include<bits/stdc++.h>
using namespace std;
bool isPerfectSquare(int num) {
    if (num < 0) return false; 
    int left = 0, right = num;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long square = (long long)mid * mid; 
        if (square == num) {
            return true; 
        } else if (square < num) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    return false; 
}
int main() {
    int num = 16; 
    if (isPerfectSquare(num)) {
        cout << num << " is a perfect square." << endl;
    } else {
        cout << num << " is not a perfect square." << endl;
    }
    return 0;
}
