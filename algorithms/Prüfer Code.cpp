#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n - 2, 0); // Changed "vi" to "vector"
    unordered_map<int, int> mp; // Changed "umap" to "unordered_map"
    for (int i = 0; i < n - 2; i++) {
        cin >> vec[i];
        mp[vec[i]]++;
    }

    set<int> leaf;
    for (int i = 1; i <= n; i++) { // Start from 1 instead of 0
        if (mp[i] == 0) leaf.insert(i);
    }

    for (int i = 0; i < n - 2; i++) {
        int x = *leaf.begin();
        leaf.erase(x);
        cout << x << " " << vec[i] << endl;
        mp[vec[i]]--;
        if (mp[vec[i]] == 0) leaf.insert(vec[i]);
    }
    cout << *leaf.begin() << " " << *leaf.rbegin() << endl;
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
    solve(); // Call the solve function directly
    return 0;
}
	