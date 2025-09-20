#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define all(a) a.begin(), a.end()
#define len(a) (int) (a.size())
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

#ifdef Energy_is_not_over
#define DEBUG for (bool ____DEBUG = true; ____DEBUG; ____DEBUG = false)
#define LOG(...) print(#__VA_ARGS__" ::", __VA_ARGS__) << endl

template<class ...Ts>
auto &print(Ts ...ts) { return ((cerr << ts << " "), ...); }

#else
#define DEBUG while (false)
#define LOG(...)
#endif

const int max_n = 100111, inf = 1000111222;

bool tp[max_n];

ll solve2(vector<ll> a, vector<ll> b) {
    if (a.empty()) {
        ll ans = 0;
        for (ll x : b) {
            ans += x;
        }
        return ans;
    }
    ll ans = a[0];
    vector<char> ord;
    ord.PB('a');
    a.erase(a.begin());
    for (int i = 0;;++i) {
        if (a.empty() && b.empty()) {
            break;
        }
        if ((i % 2 == 0 && !b.empty()) || (i % 2 == 1 && a.empty())) {
            ans += b.back();
            if (ord.back() == 'a') {
                ans += b.back();
            }
            b.pop_back();
            ord.push_back('b');
        } else {
            ans += a.back();
            if (ord.back() == 'b') {
                ans += a.back();
            }
            a.pop_back();
            ord.push_back('a');
        }
    }
    return ans;
}

ll solve() {
    int n;
    cin >> n;
    vector<ll> v[2];
    for (int i = 0; i < n; ++i) {
        cin >> tp[i];
    }
    for (int i  = 0; i < n; ++i) {
        ll a;

        cin >> a;
        v[tp[i]].PB(a);
    }
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    ll ans = max(solve2(v[0], v[1]), solve2(v[1], v[0]));
    return ans;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        cout << solve() << "\n";
    }


    return 0;
}
	