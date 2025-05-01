class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<double> dp(m+1, 0); // Use double to prevent overflow for large cases
        dp[0] = 1; // Empty t is a subsequence of any s

        for(int i = 1; i <= n; i++) {
            for(int j = m; j >= 1; j--) {
                if(s[i-1] == t[j-1]) {
                    dp[j] += dp[j-1];
                }
            }
        }

        // Optional: Print DP array
        // for(int j=0; j<=m; j++){
        //     cout<<dp[j]<<" ";
        // }
        // cout<<endl;

        return (int)dp[m];
    }
};


