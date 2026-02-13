#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class NestedInteger {
private:
    bool is_int;
    int value;
    vector<NestedInteger> list;

public:
    // Default constructor (empty list)
    NestedInteger() {
        is_int = false;
    }

    // Constructor for integer
    NestedInteger(int val) {
        is_int = true;
        value = val;
    }

    bool isInteger() const {
        return is_int;
    }

    int getInteger() const {
        return value;
    }

    void add(const NestedInteger &ni) {
        list.push_back(ni);
    }

    vector<NestedInteger>& getList() {
        return list;
    }
};

class Solution {
public:
    NestedInteger deserialize(string s) {

        if (s[0] != '[')
            return NestedInteger(stoi(s));

        stack<NestedInteger> st;
        int num = 0;
        bool negative = false;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (c == '-') {
                negative = true;
            }
            else if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '[') {
                st.push(NestedInteger());
            }
            else if (c == ',' || c == ']') {

                if (isdigit(s[i - 1])) {
                    if (negative) num = -num;
                    st.top().add(NestedInteger(num));
                    num = 0;
                    negative = false;
                }

                if (c == ']' && st.size() > 1) {
                    NestedInteger top = st.top();
                    st.pop();
                    st.top().add(top);
                }
            }
        }

        return st.top();
    }
};

int main(){
    Solution sol;
    string input = "[123,[456,[789]]]";
    NestedInteger result = sol.deserialize(input);

    cout << "Parsed successfully!" << endl;
    return 0;
}
