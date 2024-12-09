class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int bannedSize = banned.size();
    bool* vec = (bool*)calloc(n+1,sizeof(bool));

    for(int i=0; i<bannedSize; i++){
        if(banned[i] <= n)
            vec[banned[i]] = true;
    }

    int ans=0;
    for(int i=1; i<=n; i++){
        if(!vec[i]){
            if(maxSum < i)
                break;
            maxSum -= i;
            ans++;
        }
    }
    return ans;
    }
};
