
/*
Problem: Given a string s  of length  n , consisting only of lowercase English letters, find the number of different substrings in this string.
*/


int count_unique_substrings(string const& s){
    int n = s.size();
    const int p = 31;
    const long long m = 1e9 + 9;

    vector<int> p_pow(n);
    vector<long long> hashes(n+1,0) ;

    p_pow[0] = 1;    
    for(int i=1; i<n; i++){
        p_pow[i] = ( p_pow[i-1] * p ) % m;
    }

    for(int i=0; i<n; i++){
        hashes[i+1] = ( hashes[i] + ( s[i] - 'a' + 1 ) * p_pow[i] ) % m;
    }

    int cnt=0;
    for(int l=0; l<n; l++){
        unordered_set<long long> st;
        for(int i=0; i<=n-l; i++){ // or i+l<=n;
            long long cur_h = ( ( ( hashes[i+l] + m - hashes[i] ) %m ) * p_pow[n-(i+l)] ) % m;
            st.insert(cur_h);
        }
        cnt += st.size();
    }

    return cnt;
}

int main() {
    string s = "ababa";
    cout << "Unique substrings: " << count_unique_substrings(s) << endl;
    return 0;
}

// Overall Complexity:- 𝑂(𝑛^2)
