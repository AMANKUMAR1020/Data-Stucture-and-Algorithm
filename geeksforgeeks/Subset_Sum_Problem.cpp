class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        //int n = arr.size();
        // vector<vector<bool>> dp(sum+1, vector<bool>(n+1, false));
        
        // for(int i=0; i<=n; i++)
        //     dp[0][i] = true;
        
        // for(int i=1; i<=sum; i++){
        //     for(int j=1; j<=n; j++){
        //         dp[i][j] = dp[i][j-1];
        //         if(i >= arr[j-1]){
        //             dp[i][j] = dp[i][j-1] || dp[i - arr[j-1]][j-1];
        //         }
        //     }
        // }
        // return dp[sum][n];
        
        // alternative

        vector<bool> ans(sum+1,false);
        ans[0] = true;
        for(int num : arr){
            for(int i=sum; i>=num; i--){
                ans[i] = ans[i] || ans[i - num];
            }
        }
        return ans[sum];
        
    }
};
