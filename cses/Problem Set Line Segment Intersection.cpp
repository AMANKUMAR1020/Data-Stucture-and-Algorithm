#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct P {
    int x, y;
    void read() {
        cin >> x >> y;
    }
    P operator - (const P& b) const {
        return P{x - b.x, y - b.y};
    }

    void operator -= (const P& b) {
        x -= b.x;
        y -= b.y;
    }

    long long operator * (const P& b) const {
        return (long long) x * b.y - (long long) y * b.x;
    }
    long long triangle(const P& b, const P& c) const {
        return (b - *this) * (c - *this);
    }
};

void solve() {
    P p1, p2, p3, p4;
    p1.read();
    p2.read();
    p3.read();
    p4.read();

    if ((p2 - p1) * (p4 - p3) == 0) {
        if (p1.triangle(p2, p3) != 0) {
            cout << "NO\n";
            return;
        }
        for (int rep = 0; rep < 2; rep++) {
            if (max(p1.x, p2.x) < min(p3.x, p4.x) || max(p1.y, p2.y) < min(p3.y, p4.y)) {
                cout << "NO\n";
                return;
            }
        }
        swap(p1, p3);
        swap(p2, p4);
    }

for (int rep = 0; rep < 2; ++rep) {
    long long sign1 = (p2 - p1) * (p3 - p1);
    long long sign2 = (p2 - p1) * (p4 - p1);
    if ((sign1 < 0 && sign2 < 0) || (sign1 > 0 && sign2 > 0)) {
        // segment B is on left or right from line A
        cout << "NO\n";
        return;
    }
    swap(p1, p3);
    swap(p2, p4);
}
cout << "YES\n";
    return;
}

void text() {
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);   
#endif 
    return;
}

int main() {
    text();

    int t; 
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}