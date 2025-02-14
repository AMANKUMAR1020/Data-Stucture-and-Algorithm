#include<iostream>
#include <iomanip>
#include <bits/stdc++.h>

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
//using pii = pair<int, int>;
typedef long long ll;
typedef pair<ll, int> pii;

long long mod1 = 1000000007;
long long mod2 = 998244353;

// ?????(1 << 18?2^18?262144???)
vector<ll> G[1 << 19];
vector<ll> rG[1 << 19];

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep3(i,a,b) for(int i=a;i<b;i++)
#define per(i, n) for (int i = int(n) - 1; i >= int(0); i--)
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(), (x).end()

#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;

#define eb emplace_back
#define X first
#define Y second

#define all(x) (x).begin(), (x).end()

void text(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif 
    return;
}

void solve() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> dice(N);
    std::vector<int> K(N);

    for (int i = 0; i < N; ++i) {
        std::cin >> K[i];
        dice[i].resize(K[i]);
        for (int j = 0; j < K[i]; ++j) {
            std::cin >> dice[i][j];
        }
        std::sort(dice[i].begin(), dice[i].end());
    }

    double max_prob = 0.0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            double current_prob = 0.0;
            std::map<int, int> counts1;
            std::map<int, int> counts2;

            for (int face : dice[i]) {
                counts1[face]++;
            }
            for (int face : dice[j]) {
                counts2[face]++;
            }

            for (auto const& [face, count1] : counts1) {
                if (counts2.count(face)) {
                    int count2 = counts2[face];
                    current_prob += (double)count1 / K[i] * (double)count2 / K[j];
                }
            }

            max_prob = std::max(max_prob, current_prob);
        }
    }

    std::cout << std::fixed << std::setprecision(15) << max_prob << std::endl;
}

int main() {
   text();
//	int t; cin>>t;
//	while(t--){
	    solve();	
//	}
    return 0;
}

    
