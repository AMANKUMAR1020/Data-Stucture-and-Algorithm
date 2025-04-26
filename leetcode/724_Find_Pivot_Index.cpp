class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int t = 0,l=0;

        for(int num : nums)
            t += num;

        for(int i=0; i<n; i++){
            if(l == t - l - nums[i])
                return i;
            l += nums[i];
        }
        return -1;
    }
};
