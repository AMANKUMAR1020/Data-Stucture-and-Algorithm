class Solution {
  public:
    int countSubarray(vector<int>& arr, int target) {
        int n = arr.size();
        int j = 0;
        int ans = 0;
        int product = 1;
        
        for(int i=0; i<n; i++){
            
            product *= arr[i];
            
            while(j < i && product >= target){
                product /= arr[j++];
            }
            
            if(product < target)
                ans += (i-j+1);
        }
        return ans;
    }
};
