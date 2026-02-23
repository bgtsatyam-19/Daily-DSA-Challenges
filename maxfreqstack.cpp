//#include <unordered_map>
#include <stack>
#include <iostream>
#include <unordered_map>

using namespace std;

class FreqStack {
private:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> group;
    int maxFreq;

public:
    FreqStack() {
        maxFreq = 0;
    }

    void push(int val) {
        int f = ++freq[val];
        if (f > maxFreq) {
            maxFreq = f;
        }
        group[f].push(val);
    }

    int pop() {
        int val = group[maxFreq].top();
        group[maxFreq].pop();
        freq[val]--;

        if (group[maxFreq].empty()) {
            maxFreq--;
        }

        return val;
    }
};
int main() {
    FreqStack fs;
    fs.push(5);
    fs.push(7);
    fs.push(5);
    fs.push(7);
    fs.push(4);
    fs.push(5);

    cout << fs.pop() << endl; // returns 5
    cout << fs.pop() << endl; // returns 7
    cout << fs.pop() << endl; // returns 5
    cout << fs.pop() << endl; // returns 4

    return 0;
}


