class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        int leftSum = 0;

        for(int num : nums)
            totalSum += num;
        
        for(int i=0; i<n; i++){
            if(leftSum == totalSum - leftSum - nums[i])
                return i;
            leftSum += nums[i];
        }
        return -1;
    }
};
