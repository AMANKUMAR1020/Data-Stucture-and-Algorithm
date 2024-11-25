class Solution {
public:
    void sorting(int l, int h, vector<int>& nums){
        for(int i=h; i>=0; i--){
            for(int j=l; j<i; j++){
                if(nums[j] > nums[j+1])
                    swap(nums[j],nums[j+1]);
            }
        }
    }
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(n,0);

        for(int i=0; i<n; i++){
            int temp = nums[i];
            while(temp){
                vec[i] += temp&1 ? 1 : 0;
                temp >>= 1;
            }
        }
        int i=0;
        int j=1;
        while(i<n){
            j=i+1;
            while(j<n && vec[i] == vec[j])
                j++;

            sorting(i,j-1,nums);
            i=j;
        }
        sorting(i,j-1,nums);

        for(int i=1;i<n; i++){
            if(nums[i-1] > nums[i])
                return false;
        }
        return true;
    }
};
