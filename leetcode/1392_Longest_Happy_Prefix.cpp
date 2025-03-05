class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> ans = prefix_function(s);
        int maxi = ans[n-1];
        if (maxi == n) {
            return s;
        }
        
        return s.substr(0, maxi);
    }
private:
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
};
