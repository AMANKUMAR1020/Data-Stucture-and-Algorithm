#include <vector>
using namespace std;

class twoStacks {
    vector<int> vec;
    int i, j, n;

public:
    twoStacks() {
        n = 100;
        vec.resize(n);
        i = 0;
        j = n - 1; // j = 99
    }

    void push1(int x) {
        if (i <= j) {
            vec[i++] = x;
        }
    }

    void push2(int x) {
        if (i <= j) {
            vec[j--] = x;
        }
    }

    int pop1() {
        return (i > 0) ? vec[--i] : -1;
    }

    int pop2() {
        return (j < n - 1) ? vec[++j] : -1;
    }
};
