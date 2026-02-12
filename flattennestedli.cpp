#include <bits/stdc++.h>
using namespace std;

class NestedInteger {
private:
    bool is_int;
    int value;
    vector<NestedInteger> list;

public:
    // Constructor for integer
    NestedInteger(int val) {
        is_int = true;
        value = val;
    }

    // Constructor for list
    NestedInteger(vector<NestedInteger> lst) {
        is_int = false;
        list = lst;
    }

    bool isInteger() const {
        return is_int;
    }

    int getInteger() const {
        return value;
    }

    vector<NestedInteger> getList() const {
        return list;
    }
};

class NestedIterator {
private:
    stack<NestedInteger> st;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            st.push(nestedList[i]);
        }
    }

    int next() {
        int val = st.top().getInteger();
        st.pop();
        return val;
    }

    bool hasNext() {
        while (!st.empty()) {
            NestedInteger curr = st.top();

            if (curr.isInteger())
                return true;

            st.pop();
            vector<NestedInteger> lst = curr.getList();

            for (int i = lst.size() - 1; i >= 0; i--) {
                st.push(lst[i]);
            }
        }
        return false;
    }
};

int main() {
    vector<NestedInteger> nestedList = {
        NestedInteger(1),
        NestedInteger(vector<NestedInteger>{
            NestedInteger(2),
            NestedInteger(3)
        }),
        NestedInteger(4)
    };

    NestedIterator i(nestedList);

    while (i.hasNext()) {
        cout << i.next() << " ";
    }

    return 0;
}
