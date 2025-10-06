class Solution {
  public:
    int gcd(int n, vector<int> arr) {
        if(n == 0)  return 0;
        if(n == 1)  return arr[0];
        
        int ans = arr[0];
        
        for(int i=1; i<n; i++){
            ans = gcd(ans, arr[i]);
        }
        return ans;
    }
    private:
        int gcd(int num1, int num2){
            if(num2 == 0)
                return num1;
            return gcd(num2, num1%num2);
        }
};
