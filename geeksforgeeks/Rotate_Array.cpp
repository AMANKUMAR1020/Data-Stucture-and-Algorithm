class Solution {
  public:
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        d = d%n;
        reverse(arr.begin(), arr.begin()+d);
        reverse(arr.begin()+d, arr.end());
        reverse(arr.begin(), arr.end());
    }
};



// 1, 2, 3, 4, 5
// 5, 4, 3, 2, 1

// 3, 4, 5, 1, 2

// 4, 5, 1, 2, 3
