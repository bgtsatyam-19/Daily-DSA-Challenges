//Online Stock Span
#include<bits/stdc++.h>
using namespace std;
class StockSpanner {
public:
    stack<pair<int, int>> s; // pair<price, span>
    
    StockSpanner() {
        
        
    }
    
    int next(int price) {
        int span = 1;
        while (!s.empty() && s.top().first <= price) {
            span += s.top().second;
            s.pop();
        }
        s.push({price, span});
        return span;
    }
};
int main() {
    StockSpanner spanner;
    cout << spanner.next(100) << endl; // Output: 1
    cout << spanner.next(80) << endl;  // Output: 1
    cout << spanner.next(60) << endl;  // Output: 1
    cout << spanner.next(70) << endl;  // Output: 2
    cout << spanner.next(60) << endl;  // Output: 1
    cout << spanner.next(75) << endl;  // Output: 4
    cout << spanner.next(85) << endl;  // Output: 6
    return 0;
}
