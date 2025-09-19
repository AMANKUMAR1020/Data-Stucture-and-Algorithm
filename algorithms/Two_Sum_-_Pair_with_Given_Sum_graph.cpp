class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        int l = 0, r = arr.size()-1;
        sort(arr.begin(), arr.end());

        while(l<r){
            int mid = arr[l]+arr[r];
            if(target == mid)
                return true;
            else if(mid < target)
                l++;
            else
                r--;
        }
        return false;

    }
};
