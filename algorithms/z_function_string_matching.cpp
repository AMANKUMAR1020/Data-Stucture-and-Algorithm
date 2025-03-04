vector<int> z_function(string const& s){
    int n = (int)s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;

    for(int i = 1; i < n; i++){
        if(i < r){
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]){
            z[i]++;
        }
        if(i + z[i] > r){
            l = i;
            r = i + z[i];
        }
    }
    return z;
}





vector<int> find_substring(string const& s, string const& t){
    int S = s.size(), T = t.size();

    string str = t + "#" + s;  // Fix: `t + "#" + s`, so we search `t` in `s`
    vector<int> z = z_function(str);
    vector<int> ans;

    for(int i = T + 1; i < T + 1 + S; i++){  // Fix: Start after `T + 1`
        if(z[i] == T){
            ans.push_back(i - (T + 1));  // Fix: Adjust position
        }
    }
    return ans;
}
