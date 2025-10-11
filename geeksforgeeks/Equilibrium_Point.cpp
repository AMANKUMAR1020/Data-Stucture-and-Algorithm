class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        int n = arr.size();
        vector<int> left(n,0), right(n,0);
        
        if(n != 0){
            left[0] = arr[0];
            right[n-1] = arr[n-1];
        }
        
        for(int i=1; i<n; i++){
            left[i] = arr[i] + left[i-1];
            if(n-i-1 >= 0)right[n-i-1] = arr[n-i-1] + right[n-i];
        }
        for(int i=0; i<n; i++){
            if(left[i] == right[i])
                return i;
            //cout<<left[i]<<" "<<right[i]<<endl;
        }
        return -1;
    }
};
