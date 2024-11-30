#define ll long long

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ll sum=0,ans=0;

        int start=0,end=0,n=nums.size();
        unordered_map<int,int> mp;

        while(end<n){
            int val = nums[end];
            int lastindex =  mp.count(val) ? mp[val] : -1;

            while(start <= lastindex || end - start + 1>k){
                sum -= nums[start];
                start++;
            }

            mp[val] = end;
            sum += nums[end];
            if(end - start + 1 == k){
                ans = max(ans,sum);
            }
            end++;
        }   
        return ans;     
    }
};
