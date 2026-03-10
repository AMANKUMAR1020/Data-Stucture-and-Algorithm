class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int n = nums.size();
        int xr = 0;

        for(int i=0;i<n;i++)
            xr ^= nums[i];

        for(int i=1;i<=n;i++)
            xr ^= i;

        int setBit = xr & (-xr);

        int x = 0, y = 0;

        for(int num : nums){
            if(num & setBit) x ^= num;
            else y ^= num;
        }

        for(int i=1;i<=n;i++){
            if(i & setBit) x ^= i;
            else y ^= i;
        }

        // determine duplicate
        for(int num : nums){
            if(num == x)
                return {x,y};
        }

        return {y,x};
    }
};