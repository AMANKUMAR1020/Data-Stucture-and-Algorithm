class kadaneAlgorithms {
    public:
        int solve(vector<int>& nums){
            int ans = nums[0];
            int temp = nums[0];

            for(int i=1; i<n; i++){
                temp = max(nums[i], temp+nums[i]);
                ans = max(ans, temp);
            }
            return ans;
        }
}


// alternative
/*
class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int ans = INT_MIN;
        int temp = 0, n = arr.size();

        if(n==0) return 0;
        if(n==1) return arr[0];

        for(int i=0; i<n; i++){
            // temp += arr[i];
            // if(temp < 0){
            //     temp = 0;
            // }else{
            //     ans = max(ans, temp);
            // }
            
            temp = max(arr[0], temp + arr[0]);
            ans = max(ans, temp);
        }
        return ans;
    }
};
*/