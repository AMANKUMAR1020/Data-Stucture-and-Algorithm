#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    void deleteMid(stack<int>& s) {
        int n = s.size();
        int mid = n/2;
        int i = 0;
        stack<int> t;

        while (!s.empty()) {
            if (i++ != mid) {
                t.push(s.top());
            }
            s.pop();
        }

        while (!t.empty()) {
            s.push(t.top());
            t.pop();
        }
    }
};
