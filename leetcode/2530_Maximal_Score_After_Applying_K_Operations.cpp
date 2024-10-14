class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> maxHeap;
        long long ans=0;
        
        for(int n : nums)
            maxHeap.push(n);

        while(k--){
            int val = maxHeap.top(); maxHeap.pop();
            int temp = ceil(val/3.0);

            maxHeap.push(temp);
            ans += val;
        }
        return ans;
    }
};
