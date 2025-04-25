class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if(s[0] != '0' || s[n-1] != '0') return false;
        
        vector<bool> dp(n, false);
        dp[0] = true;
        int farthest = 0;

        for(int i = 0; i < n; i++) {
            if(!dp[i]) continue;
            
            // Calculate window bounds
            int start = i + minJump;
            int end = min(i + maxJump, n - 1);
            
            // Ensure we don't reprocess old positions
            start = max(start, farthest + 1);
            
            for(int j = start; j <= end; j++) {
                if(s[j] == '0') {
                    dp[j] = true;
                    if(j == n-1) return true;
                }
            }
            farthest = max(farthest, end); // Track global maximum
        }
        
        return dp[n-1];
    }
};
