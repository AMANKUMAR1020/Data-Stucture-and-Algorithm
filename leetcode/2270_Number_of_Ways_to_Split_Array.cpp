class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        long long leftSum = 0;
        int count = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            leftSum += nums[i];
            totalSum -= nums[i];
            if (leftSum >= totalSum) {
                count++;
            }
        }
        return count;
    }
};


/*
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
    int n = nums.size();
    int *arr1 = new int[n-1]();
    int *arr2 = new int[n-1]();
    
    // Calculate prefix sums (arr1)
    for(int i = 1; i < n - 1; i++) {
        arr1[i] = arr1[i-1] + nums[i-1];
    }
    
    // Calculate suffix sums (arr2)
    for(int i = n-2; i >= 0; i--) {
        arr2[i] = arr2[i+1] + nums[i+2];
    }
    
    int ans = 0;
    for(int i = 1; i < n-1; i++) {
        if(arr1[i] >= arr2[i]) ans++;
    }
    return ans;
    }
};
*/
