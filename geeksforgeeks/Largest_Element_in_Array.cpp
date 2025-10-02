class Solution {
  public:
    int largest(vector<int> &arr) {
        int ans = INT_MIN;
        for(int a : arr)
            if(ans < a)
                ans = a;
        return ans;
    }
};
