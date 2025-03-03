/*
@ Q.Problem: Given a list of n  strings  s , each no longer than  m  characters, find all the duplicate strings and divide them into groups.
*/

#include <bits/stdc++.h>
using namespace std;

long long compute_hash(const string& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long value = 0;
    long long p_pow = 1;

    for (char c : s) {
        value = (value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return value;
}

vector<vector<int>> get_duplicate(vector<string>& vec) {
    int n = vec.size();
    vector<pair<long long, int>> g(n);

    // Compute hash for each string and store it with its index
    for (int i = 0; i < n; i++) {
        g[i] = {compute_hash(vec[i]), i};
    }

    // Sort by hash values
    sort(g.begin(), g.end());

    vector<vector<int>> ans;
    
    // Group indices with the same hash value
    for (int i = 0; i < n; i++) {
        if (i == 0 || g[i].first != g[i - 1].first) {
            ans.push_back({g[i].second});
        } else {
            ans.back().push_back(g[i].second);
        }
    }

    return ans;
}

int main() {
    vector<string> vec = {"apple", "banana", "apple", "orange", "banana"};
    vector<vector<int>> duplicates = get_duplicate(vec);

    for (auto group : duplicates) {
        cout << "[ ";
        for (int index : group) {
            cout << index << " ";
        }
        cout << "]\n";
    }

    return 0;
}


/*
TC:- 𝑂(𝑁𝐿+𝑁log𝑁)

Expected outcomes:-
[ 0 2 ]
[ 1 4 ]
[ 3 ]
Here:

"apple" appears at indices [0, 2].
"banana" appears at indices [1, 4].
"orange" appears only at [3].

*/
