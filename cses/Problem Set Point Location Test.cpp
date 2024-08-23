#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct P{
    int x,y;
    void read(){
        cin>>x>>y;
    }
    P operator - (const P& b) const {return P{x - b.x , y -b.y};}

    void operator -= (const P& b){
        x -= b.x;
        y -= b.y;
    }

    long long operator * (const P& b) const{
        return (long long) x * b.y - (long long) y * b.x;
    }
};

void solve(){

    P p1,p2,p3;
    p1.read();
    p2.read();
    p3.read();

    p3 -= p1;
    p2 -= p1;

    long long cross_product = p2*p3;
    if(cross_product < 0){
        cout<<"RIGHT\n";
    }
    else if(cross_product > 0){
        cout<<"LEFT\n";
    }
    else {
        cout<<"TOUCH\n";
    }
    return ;
}

void text(){
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
	