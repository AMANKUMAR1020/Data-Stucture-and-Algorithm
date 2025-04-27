class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
        int m = n / 2;

        for(int num : nums)
            totalSum += num;
        
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = n - 1;
        int leftSum = 0;
        int mini = INT_MAX;
        
        // Select exactly m elements
        for(int i = 0; i < m; i++) {
            // Calculate potential differences
            int temp1 = abs(2 * (leftSum + nums[left]) - totalSum);
            int temp2 = abs(2 * (leftSum + nums[right]) - totalSum);
            
            // Choose the better option
            if(temp1 < temp2) {
                leftSum += nums[left];
                mini = min(mini, temp1);
                left++;
            } else {
                leftSum += nums[right];
                mini = min(mini, temp2);
                right--;
            }
        }
        
        return mini;
    }
};
