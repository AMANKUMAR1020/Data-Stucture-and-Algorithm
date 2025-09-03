class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int s=0,l=n-1;
        
        vector<int> sortNums = nums;
        sort(sortNums.begin(), sortNums.end());

        while(s < l){
            if(sortNums[s] == nums[s])
                s += 1;
            else if(sortNums[l] == nums[l])
                l -= 1;
            else 
                break;
        }
        int ans = l - s;
        return  ans ? ans + 1 : 0;
    }
};
