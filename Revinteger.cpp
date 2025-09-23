#include <bits/stdc++.h>
using namespace std;

int reverseInt(int x) {
    long long rev = 0;
    while (x != 0) {
        int pop = x % 10;
        x /= 10;
        rev = rev * 10 + pop;
        if (rev > INT_MAX || rev < INT_MIN) return 0;
    }
    return (int)rev;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x;
    if (!(cin >> x)) return 0;
    cout << reverseInt(x) << '\n';
    return 0;
}
