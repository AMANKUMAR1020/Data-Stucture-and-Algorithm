// User function template for C++
class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        int i=0;
        while(i < n){
            if(mat[i][0] <= x  && x <= mat[i][m-1]){
                int j = 0;
                while(j < m){
                    if(mat[i][j] == x)return true;
                    j++;
                }
            }
            i++;
        }
        return false;
    }
};


// [1, 2, 3],
// [4, 5, 6],
// [7, 8, 9]

// 62

// [3, 30, 38],
// [20, 52, 54],
// [35, 60, 69]

