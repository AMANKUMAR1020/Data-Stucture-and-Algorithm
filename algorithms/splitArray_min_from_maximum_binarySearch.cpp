#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums, int mid) {
    int sum = 0;
    int cnt = 1; // Start with one subarray
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        if (sum + nums[i] <= mid) {
            sum += nums[i]; // Add to the current subarray
        } else {
            cnt++; // Create a new subarray
            sum = nums[i]; // Start sum with the current element
        }
    }
    return cnt; // Return the number of subarrays formed
}

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end()); // Minimum possible max sum
        int right = accumulate(nums.begin(), nums.end(), 0); // Maximum possible max sum

        while (left < right) {
            int mid = left + (right - left) / 2;
            int lsum = solve(nums, mid);
            if (lsum > k) {
                left = mid + 1; // Increase the sum limit
            } else {
                right = mid; // Try a smaller sum limit
            }
        }
        return left; // The minimum possible maximum sum
    }
};
