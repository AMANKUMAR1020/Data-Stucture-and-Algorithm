class Solution {
public:
    vector<int> getRow(int m) {
        int n = 34;
        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            vector<int> vec(i+1,1);
            for(int j=1; j<i; j++){
                vec[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            ans.push_back(vec);
        }
        return ans[m];
    }
};



/*
class Solution {
public:
    vector<int> getRow(int m) {

        int n = 33;
        vector<vector<int>> ans;

        for(int i=1; i<=n; i++){
            vector<int> vec(i,1);
            for(int j=1; j<i-1; j++){
                vec[j] = ans[i-2][j-1] + ans[i-2][j];
            }
            ans.push_back(vec);
        }
        return ans[m];
    }
};
*/
