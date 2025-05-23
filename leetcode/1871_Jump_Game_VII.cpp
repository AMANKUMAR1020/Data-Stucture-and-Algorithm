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





/*
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if(s[n-1] != '0')
            return false;

        vector<bool> dp(n,0);
        dp[0] = true;
        int far = 0;

        for(int i=0; i<n; i++){
            if(!dp[i])
                continue;
            
            int start = min(i+minJump, far + 1);
            int end = min(i+maxJump, n - 1);

            for(int j = start; j<=end; j++){
                if(s[j] == '0'){
                    dp[j] = true;
                    if(j == n-1)
                        return true;
                }
                far = end;
            }
        }
        return dp[n-1];
    }
};



class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> vec(n,0);

        int val = dp(0,s,0,vec,minJump,maxJump, n);

        cout<<endl;
        for(int i : vec){
            cout<<i<<" ";
        }

        return val == n - 1;
    }
private:
    int dp(int ind, string &s, int maxval, vector<int> &vec,int minJump, int maxJump,int &n){
        if(ind >= n)
            return maxval;

        if(vec[ind])
         return vec[ind];
        
        if(s[ind] == '0')
            vec[ind] = maxval;
    
        int val = vec[ind];
        for(int i = ind + minJump; i <= min(ind + maxJump, n - 1); i++){
            if(s[i] == '0')
                val = max(val, dp(i,s,i,vec,minJump,maxJump,n));
            cout<<i<<" "<<vec[i]<<endl;
        }

        return val;

    }
};
*/
