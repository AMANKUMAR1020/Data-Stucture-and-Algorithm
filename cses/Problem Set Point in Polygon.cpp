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

bool segment_contains(P a,P b, P c){
    if(a.triangle(b,c) != 0){
        return false;
    }
    return min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x)
            && min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
}
bool intersect(P p1, P p2, P p3, P p4) {
    if((p2 - p1) * (p4 - p3) == 0) {
        // two segment are parallel
        // if((p2 - p1) * (p3 - p1) != 0) {
        if(p1.triangle(p2, p3) != 0) {
            return false;
        }
        // check if two bounding boxes intersect
        for(int rep = 0; rep < 2; ++rep) {
            // rectangle A on left from rectangle B   or   A below rectangle B
            if(max(p1.x, p2.x) < min(p3.x, p4.x) || max(p1.y, p2.y) < min(p3.y, p4.y)) {
                return false;
            }
            swap(p1, p3);
            swap(p2, p4);
        }
        return true;
    }
    for(int rep = 0; rep < 2; ++rep) {
        long long sign1 = (p2 - p1) * (p3 - p1);
        long long sign2 = (p2 - p1) * (p4 - p1);
        if((sign1 < 0 && sign2 < 0) || (sign1 > 0 && sign2 > 0)) {
            // segment B is on left or right from line A
            return false;
        }
        swap(p1, p3);
        swap(p2, p4);
    }
    return true;
}

void solve() {
    int n,m; cin>>n>>m;
    std::vector<P> polygon(n);

    for(P& p : polygon)p.read();

    for(int rep = 0; rep<m; ++rep){
        P p;
        p.read();
        P out = P{p.x + 1, 1000000001ll};
        bool is_on_boundary = false;
        int count = 0;

        for(int i=0; i<n; i++){
            int j = (i==n-1 ? 0 : i+1);
            if(segment_contains(polygon[i],polygon[j],p)){
                is_on_boundary = true;
                break;
            }
            if(intersect(p,out,polygon[i],polygon[j])){
                count++;
            }
        }

        if(is_on_boundary){
            cout<<"BOUNDARY\n";
        }else if(count %2 == 0){
            cout<<"OUTSIDE\n";
        }else{
            cout<<"INSIDE\n";
        }
    }
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
    solve();
    return 0;
}