#define ONLINEJUDGE
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

template<typename Container>
void sorting(Container &x) { sort(x.begin(), x.end()); }

// vscan for (auto &x : v) cin >> x;
// for(auto &x : v) cout << x << " ";
// using pb(x) push_back(x);

typedef long long int ll;

#define MAX 1e9
#define yes cout<<"YES"<<endl;
#define no  cout<<"NO"<<endl;

void text(){
	#ifdef ONLINEJUDGE
		freopen("input.txt", "r",stdin);
		freopen("output.txt", "w",stdout);
	#endif
}


void solve() {
    ll n; cin>>n;
    ll mini = INT_MAX;
    ll maxi = INT_MIN;

    std::vector<ll> v(n);
    for (auto &x : v) {
        cin >> x;

        mini = min(x, mini);
        maxi = max(x, maxi);
    }

    ll mid = (mini + maxi) / 2;

    cout<<max(mid - mid, maxi - mid)<<endl;
    
//  cout << (mx - mn + 1) / 2 << '\n';
//  This matches all sample outputs, including:

    return ;
}


int main(){        
	text();
    int t=1; cin>>t;
    while(t--){
    	solve();
    }
}

