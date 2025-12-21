class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        int l = 0;
        int r = n-1;
        int maxL = arr[l];
        int maxR = arr[r];
        int ans = 0;
        
        while(l < r){
            if(maxL < maxR){
                ans += maxL - arr[l];
                maxL = max(maxL, arr[++l]);
            }else{
                ans += maxR - arr[r];
                maxR = max(maxR, arr[--r]);
            }
        }
        return ans;
    }
};


/*
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int num = 0;
        int n = arr.size();
        vector<int> l(n);
        vector<int> r(n);
        
        for(int i=0; i<n; i++)
            l[i] = i==0 ? arr[i] : max(arr[i], l[i-1]);
        
        for(int i=n-1; i>=0; i--)
            r[i] = i==n-1 ? arr[i] : max(arr[i], r[i+1]);
        
        int ans = 0;
        
        for(int i=0; i<n; i++)
            ans += min(l[i], r[i]) - arr[i];
        
        return ans;
    }
};


arr = 3,0,1,0,4,0,2
l  =  3,3,3,3,4,4,4
r  =  4,4,4,4,4,2,2
ans = 1,3,0,3,0,2,0

*/