class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int ans = 0;
        int temp1 = 0;
        int n = prices.size();

        for(int i=n-1; i>=0; i--){
            temp1 = max(temp1, prices[i]);
            ans = max(ans, temp1 - prices[i]);
        }
        return ans;
    }
};


