#include<iostream>
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
bool isValid(const vector<int>& seq, int K) {
    int sum = 0;
    for (int num : seq) {
        sum += num;
    }
    return sum % K == 0;
}

// Recursive function to generate sequences
void generateSequences(int N, int K, const vector<int>& R, vector<int>& seq, int index) {
    if (index == N) {
        // Check if the sequence is valid
        if (isValid(seq, K)) {
            // Print the sequence
            for (int num : seq) {
                cout << num << " ";
            }
            cout << endl;
        }
        return;
    }

    // Generate sequences for the current index
    for (int i = 1; i <= R[index]; i++) {
        seq[index] = i;
        generateSequences(N, K, R, seq, index + 1);
    }
}
void solve() {
    int N, K;
    cin >> N >> K;

    vector<int> R(N);
    for (int i = 0; i < N; i++) {
        cin >> R[i];
    }

    vector<int> seq(N);
    generateSequences(N, K, R, seq, 0);
}
int main() {
//    text();
    solve();
    return 0;
}



/*
Problem Statement
Print all integer sequences of length 
N that satisfy the following conditions, in ascending lexicographical order.

The 
i-th element is between 
1 and 
R 
i
​
 , inclusive.
The sum of all elements is a multiple of 
K.
What is lexicographical order for sequences?
Constraints
All input values are integers.
1≤N≤8
2≤K≤10
1≤R 
i
​
 ≤5
Input
The input is given from Standard Input in the following format:

N 
K
R 
1
​
  
R 
2
​
  
… 
R 
N
​
 
Output
Print the answer in the following format, where 
X is the number of sequences to print, the 
i-th of which is 
A 
i
​
 =(A 
i,1
​
 ,A 
i,2
​
 ,…,A 
i,N
​
 ):

A 
1,1
​
  
A 
1,2
​
  
… 
A 
1,N
​
 
A 
2,1
​
  
A 
2,2
​
  
… 
A 
2,N
​
 
⋮
A 
X,1
​
  
A 
X,2
​
  
… 
A 
X,N
​
 
Sample Input 1
Copy
3 2
2 1 3
Sample Output 1
Copy
1 1 2
2 1 1
2 1 3
There are three sequences to be printed, which are 
(1,1,2),(2,1,1),(2,1,3) in lexicographical order.

Sample Input 2
Copy
1 2
1
Sample Output 2
Copy
There may be no sequences to print.
In this case, the output can be empty.

Sample Input 3
Copy
5 5
2 3 2 3 2
Sample Output 3
Copy
1 1 1 1 1
1 2 2 3 2
1 3 1 3 2
1 3 2 2 2
1 3 2 3 1
2 1 2 3 2
2 2 1 3 2
2 2 2 2 2
2 2 2 3 1
2 3 1 2 2
2 3 1 3 1
2 3 2 1 2
2 3 2 2 1
*/
