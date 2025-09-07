class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n,0);
        int m = n/2;
        for(int i=0; i<m; i++){
            ans[i] = i+1;
            ans[n-i-1]= -(i+1);
        }
        return ans;
    }
};
