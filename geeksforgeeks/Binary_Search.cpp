class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        int l = 0;
        int r = arr.size()-1;
        int ans = -1;
        
        while(l < r){
            int mid = (l + (r-l)/2);
            
            if(arr[mid] == k){
                ans = mid;
                r = mid;
            }
            else if(arr[mid] < k){
                l = mid + 1;
            }
            else 
                r = mid;
        }
        return ans;
    }
};
// 3
// 1 1 1 2 2 3 3 3 3 3 3 4 4 4 5 5 5
// 10
// 5
