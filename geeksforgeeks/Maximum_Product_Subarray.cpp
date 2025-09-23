class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        int n = arr.size();
        int mini = arr[0];
        int maxi = arr[0];
        int ans = arr[0];
        
        for(int i=1; i<n; i++){
            int temp = max({arr[i], arr[i]*mini, arr[i]*maxi});
                mini = min({arr[i], arr[i]*mini, arr[i]*maxi});
            maxi = temp;
            ans = max(ans, maxi);
        }
        return ans;
    }
    
    // alternative approch
    int maxProduct(vector<int> &arr) {
        int n = arr.size();
        int ans = INT_MIN;
        int leftToright = 1;
        int rightToleft = 1;

        for(int i=0; i<n; i++){
            if(leftToright == 0 ) leftToright = 1;
            if(rightToleft == 0 ) rightToleft = 1;

            leftToright *= arr[i];
            rightToleft *= arr[n-i-1];
            
            ans = max({leftToright, rightToleft, ans});
        }
        return ans;
    }
};

