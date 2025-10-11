

class Solution {
  public:
    long long countSubArrayProductLessThanK(const vector<int>& arr, int n,
                                            long long k) {
        int i = 0, j = 0;
        long long cnt = 0;
        long long product = 1;
        
        while(i<n && j<n){
            if(arr[j] < k){
                if(product*arr[j] < k){
                    cnt += j - i + 1;
                    product *= arr[j++];
                }else{
                    product /= arr[i++];
                }
            }else{
                product = 1;
                i = ++j;
            }
        }
        return cnt;
    }
};

