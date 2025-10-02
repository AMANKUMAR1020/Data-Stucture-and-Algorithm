class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int ind1 = divid(arr);
        if (ind1 == -1) {
            reverse(arr.begin(), arr.end());
            return;
        }
        int ind2 = minNum(arr, ind1);
        swap(arr[ind1], arr[ind2]);
        reverase(arr.begin() + ind1 + 1, arr.end());
    }
    private:
        int divid(vector<int>& arr){
            for (int i = arr.size() - 2; i >= 0; i--) {
                if (arr[i] < arr[i + 1])
                    return i;
            }
            return -1;
        }
        
        int minNum(vector<int>& arr,int ind){
            int val = arr[ind];
            int idx = ind+1;
            for (int i = ind + 1; i < arr.size(); i++) {
                if (arr[i] > val && arr[i] <= arr[idx])
                    idx = i;
            }
            return idx;
        }
        
};
