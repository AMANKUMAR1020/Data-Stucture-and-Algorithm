#include<iostream>
#include <bits/stdc++.h>
#include <string>


using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vpii = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;
using vvvi = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<long long>>>;
using vvvvi = vector<vector<vector<vector<int>>>>;
using pll = pair<long long, long long>;
using umap = unordered_map<int, int>;
using umapci = unordered_map<char,int>;
//auto compare = [](const T& a, const T& b) { return a.d > b.d; };

// using pii = pair<int, int>;

// mod???
long long mod1 = 1000000007;
long long mod2 = 998244353;

// ?????(1 << 18?2^18?262144???)
vector<ll> G[1 << 19];
vector<ll> rG[1 << 19];


// matrix sum
//        return accumulate(matrix.begin(), matrix.end(), 0, [](int a, const auto& A) { return a + accumulate(A.begin(), A.end(), 0); });

// rep???
// 0??n-1??
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// a??b-1??
#define rep3(i,a,b) for(int i=a;i<b;i++)
// n-1??0??
#define per(i, n) for (int i = int(n) - 1; i >= int(0); i--)
// b-1??a??
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
// ??for????
#define fore(i,a) for(auto &i:a)
// sort(A.begin(), A.end())?sort(all(A))????????
#define all(x) (x).begin(), (x).end()

#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;

#define eb emplace_back
#define X first
#define Y second

#define all(x) (x).begin(), (x).end()

#define cinp(v)        \
    for (auto &it : v) \
        cin >> it;

void text(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);   
#endif          
    return;
}

const int MAXN = 2e5+7;
typedef long long LL;
typedef pair<LL, LL> PII;
const LL N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
 


int n, k, a[200000];
 
void solve(){
    cin >> n >> k;
    for (int i=0; i<n; ++i) cin >> a[i];
    sort(a, a+n);
    ll s=0, b=0;
    int c=0;
    for (int i=0; i<n && s<(ll)k; ++i){
        a[i]-=b;
        s += (ll)(a[i])*(ll)(n-i);
        b += (ll)a[i];
        if(s < (ll)k)
            c++;
    }
    cout << k+c << "\n";
}


int main() {
    text();
    int t=1; cin>>t;

    while( t-- )
        solve();
    
    return 0;

}

