class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(),0);

        while(l < r){
            int mid = l + (r-l)/2;
            int val = solve(mid,nums);
            if(k < val){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return l;
    }
private:
    int solve(int mid, vector<int>& nums){
        int cnt = 1;
        int start = 0;
        for(int i=0; i<nums.size(); i++){
            if(start + nums[i] <= mid){
                start += nums[i];
            }else{
                start = nums[i];
                cnt++;
            }
        }
        return cnt;
    }
};











class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1, 0);
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LLONG_MAX));

        // Calculate prefix sum
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        // Initialize dp
        dp[0][0] = 0;

        // Fill dp table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, m); j++) {
                for (int k = 0; k < i; k++) {
                    dp[i][j] = min(dp[i][j], max(dp[k][j - 1], prefixSum[i] - prefixSum[k]));
                }
            }
        }

        return dp[n][m];
    }
};
/*
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1,0));
        
        for(int i = 0; i < n; i++){
            for(int l = 0; l < k; l++){
                if(l == k-1){
                    for(int j=i; j<n; j++){
                        dp[i][l] += nums[j];
                    }
                }
                else
                    dp[i][l] = nums[i];
            }
        }
        return dp[n][k];
    }
};
*/
