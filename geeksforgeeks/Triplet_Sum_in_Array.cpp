class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int fir = 0;
        int lst = n-1;

        while(fir < lst){
            for(int i=lst; i>fir; i--){
                int temp = arr[fir] + arr[i];
                if(temp < target){
                    if( bs(fir+1,i-1, target - temp, arr) )
                        return true;
                }
            }
            fir++;
        }
        return false;
    }
    
    bool bs(int l, int r, int target, vector<int>& arr){
    while(l<=r){
        int mid = l + (r-l)/2;
        
        if(arr[mid] == target)  
            return true;
        else if(arr[mid] < target)
            l = mid+1;
        else 
            r = mid-1;
    }
    return false;
}
};



/*
class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        int n = arr.size();
        int m = accumulate(arr.begin(), arr.end());
        vector<bool> vec(m,false);
        
        res(arr,-1,n,target,vec);
    }
    private:
     bool res(vector<int>& arr, int i, int n, int target, vector<bool>& vec){
        if(i==n){
            return target == 0;
        }
        
        bool flag = false;
        
        for(int j=i+1; j<n; j++)}{
            if(vec[]){
                return true;
            }
            if(j < n && arr[j] <= target){
                flag = flag || res(arr, j, n, target - arr[j]);
            }
        }
        return flag;
     }
};


class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        // Code Here
        int n = arr.size();
        vector<vector<bool>> vec(n+1, vector<bool>(target+1,false));
        
        vec[0][0]=true;
        
        for(int i=1; i<=n; i++){
            vec[0][i] = true;
        }
        for(int i=0; i<=n; i++){
            for(int j=i+1; j <= target; j++){
                if(j + arr[i] <= target){
                    if(vec[])
                        vec[i][j] = vec[i][j] || vec[][];
                    else
                        vec[ j + arr[i] ][j] = true;
                }else{
                    
                }
            }
        }
    }
};

1, 4, 45, 6, 10, 8
1, 4, 6, 8, 10, 45



*/
