class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        int cnt = 0;
        
        while(i < n && j < m){
                
            if(a[i] < b[j]){
                if(k == i + j + 1)
                    return a[i];
                i++;
                
            }else{
                if(k == i + j + 1)
                    return b[j];
                j++;
            }
        }
        
        while(i < n){
            if(k == i + j + 1)
                return a[i];
            i++;
        }
        
        while(j < m){
            if(k == i + j + 1)
                return b[j];
            j++;
        }
        return -1;
    }
};
