#include <iostream>
using namespace std;

class Solution {
public:
    
    long long countTrailingZeroes(long long n) {
        long long count = 0;

        while (n > 0) {
            n /= 5;
            count += n;
        }

        return count;
    }

    int preimageSizeFZF(int k) {

        long long left = 0;
        long long right = 5LL * (k + 1);

        while (left < right) {

            long long mid = left + (right - left) / 2;

            if (countTrailingZeroes(mid) < k) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return countTrailingZeroes(left) == k ? 5 : 0;
    }
};

int main() {

    Solution obj;

    int k;
    cin >> k;

    cout << obj.preimageSizeFZF(k);

    return 0;
}