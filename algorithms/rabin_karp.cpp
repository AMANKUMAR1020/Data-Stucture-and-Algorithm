    vector<int> rabin_karp(string const& s, string const & t){
    const int p = 31;
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();
    int n = max(S,T);

    vector<long long> p_pow(n,1);

    for(int i=1; i<(int)p_pow.size(); i++){
        p_pow[i] = (p_pow[i-1]*p) % m;
    }

    vector<long long> hashes(T+1,0);
    hashes[0]=0;
    for(int i=0; i<T; i++){
        hashes[i+1] = (hashes[i] + (t[i] - 'a' + 1)*p_pow[i])%m;
    }

    long long hs = 0;
    for(int i=0; i<S; i++){
        hs = (hs + (s[i] - 'a' + 1) * p_pow[i] ) % m;
    }

    vector<int> occerance;
    for(int i=0; i+S-1 < T; i++){
        long long cur_h = (hashes[i+S] + m - hashes[i]) % m;
        if(cur_h == (hs*p_pow[i])%m){
            occerance.push_back(i);
        }
    }
    return occerance;
}




int main() {
    string text = "ababcababc";
    string pattern = "abc";

    vector<int> occurrences = rabin_karp(pattern, text);

    cout << "Pattern found at indices: ";
    for (int idx : occurrences) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}


// Overall Complexity:- O(T+S) (Linear Time) ✅
