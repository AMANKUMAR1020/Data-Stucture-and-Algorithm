class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int n = arr.size();
        // if(n == 1)
        //     return a;
            
        int ans = 0;
        int z = 0;
        int j = 0;

        for(int i=0; i<n; i++){
            
            if(arr[i] == 0)
                z++;
            
            while(j <= i &&  z > k){
                if(arr[j] == 0)
                    z--;
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
