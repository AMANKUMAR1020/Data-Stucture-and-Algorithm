/*
  prefix function
*/


vector<int> prefix_function(string const& s){
    int n = s.size();

    vector<int> pi(n);

    for(int i=1; i<n; i++){
        int j = pi[i-1];

        while(j>0 && s[i] != s[j]){
            j = pi[j-1];
        }
        if(s[i] == s[j]){
            j++;
        }
        pi[i] = j;
    }

    return pi;
}

/*
   Pattern Searching- The Knuth-Morris-Pratt algorithm:
*/

vector<int> KMPAlgorithm_patternSearching(string const& s, string const& t){
    int T = t.size(), S = s.size();
    string str = s + "#" + t;

    vector<int> pi = prefix_function(str);
    vector<int> ans;

    for(int i = T+1; i<T+S+1; i++){
        if(pi[i] == S){
            ans.push_back(i - 2*S);
        }
    }

    return ans;
}

/*
    Count the number of occurrences of each prefix in same string
*/
vector<int> Counting_number_of_occurrences_of_each_prefix(string const& s){
    int n = s.size();

    vector<int> pi = prefix_function(s);
    vector<int> cnt(n+1);

    for(int i=0; i<n; i++){
        cnt[pi[i]]++;
    }

    for(int i=n-1; i>0; i--){
        cnt[pi[i-1]] += cnt[i];
    }

    for(int i=0; i<=n; i++){
        cnt[i]++;
    }
    
    return cnt;
}
