//Implement Queue using Stacks
#include <stack>
#include <iostream>
#include <stdexcept>
using namespace std;    
class MyQueue {
private:
    stack<int> s1, s2;
public:
    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) {
            throw runtime_error("Queue is empty");
        }
        int val = s2.top();
        s2.pop();
        return val;
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) {
            throw runtime_error("Queue is empty");
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};
int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << q.peek() << endl; // returns 1
    cout << q.pop() << endl;  // returns 1
    cout << q.empty() << endl; // returns false
    return 0;
}
