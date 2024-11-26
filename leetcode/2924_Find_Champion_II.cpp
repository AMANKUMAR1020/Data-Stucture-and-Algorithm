class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
    vector<bool> vec(n, true);

    for(vector<int>& edge : edges)
        vec[edge[1]] = false;

    int val=0,cnt=0;
    for(int i=0; i<n; i++){
        if(vec[i]){
            val=i;
            cnt++;
        }
    }
    if(cnt > 1)
        return -1;
    return val;
    }
};
