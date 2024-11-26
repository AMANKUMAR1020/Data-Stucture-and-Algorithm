class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();

        vector<int> prefixXOR(n);
        prefixXOR[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefixXOR[i] = prefixXOR[i - 1] ^ nums[i];
        }

        vector<int> ans(n);
        int mask = (1 << maximumBit) - 1;

        for (int i = 0; i < n; i++) {
            // find k to maximize value
            int currentXOR = prefixXOR[n - 1 - i];
            ans[i] = currentXOR ^ mask;
        }

        return ans;
    }
};







// class Solution {
// public:
//     vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
//         int n = nums.size();
//         int limit =  pow(2,maximumBit);
//         int maxi = 0;
        
//         if(maxi < limit)
//             maxi = max(maxi,nums[0]);
            
//         for(int i=1; i<n; i++){
//             if(maxi < limit)
//                 maxi = max(maxi,nums[i]);
//             nums[i] ^= nums[i-1];
//         }
//         for(int i=0; i<n/2; i++){
//             nums[i] = nums[i]^maxi;
//             nums[n-1-i] = nums[n-1-i]^maxi;
//            swap(nums[i],nums[n-1-i]);
//         }
//         return nums;
//     }
// };
