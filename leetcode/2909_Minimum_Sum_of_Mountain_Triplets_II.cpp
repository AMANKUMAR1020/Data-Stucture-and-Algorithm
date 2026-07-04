class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> l(n), r(n);
        int ans = INT_MAX;
        l[0] = nums[0];
        r[n-1] = nums[n-1];

        for(int i=1; i<n; i++){
            l[i] = min(l[i-1], nums[i]);
            r[n-i-1] = min(r[n-i], nums[n-i]);
        }

        for(int i=0; i<n; i++){
            if(l[i] < nums[i] && r[i] < nums[i]){
                ans = min(ans, l[i] + nums[i] + r[i]);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
