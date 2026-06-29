class Solution {
  public:
    bool bs(vector<int>& stalls, int k, int m){
        int cnt = 1;
        int p = stalls[0];
        int n = stalls.size();

        for(int i=1; i<n; i++){
            if(stalls[i] - p >= m){
                p = stalls[i];
                cnt++;
            }
        }
        return cnt >= k;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        
        sort(stalls.begin(), stalls.end());
        
        int n = stalls.size();
        int l = 0;
        int r =  stalls[n-1] - stalls[0];
        int ans = 0;
        
        while(l <= r){
            
            int m = l + (r-l)/2;
            
            if(bs(stalls, k, m)){
                ans = m;
                l = m+1;
            }else{
                r = m-1;
            }
        }
        return ans;
    }
};
