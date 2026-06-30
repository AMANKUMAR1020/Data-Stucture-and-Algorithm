class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = -1;
        int h = 0;
        int v = 0;
        
        
        for(int i=0; i<n; i++){
            h = 0; v = 0;
            for(int j=0; j<n; j++){
                v += mat[j][i];
                h += mat[i][j];
            }
            
            if(h == 1 && v == n)
                ans = i;
        }
        
        return ans;
    }
};

/*
class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();

        int candidate = 0;

        for (int i = 1; i < n; i++) {
            if (mat[candidate][i] == 1)
                candidate = i;
        }

        for (int i = 0; i < n; i++) {
            if (i == candidate)
                continue;

            if (mat[candidate][i] == 1 || mat[i][candidate] == 0)
                return -1;
        }

        return candidate;
    }
};

*/
