class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        int cnt = 0;
        vector<int> vec;
        
        while(i < n && j < m){
                
            if(a[i] < b[j]){
                if(!vec.empty() && vec.back() == a[i]){
                    i++;
                    continue;
                }
                vec.push_back(a[i++]);
            }else{
                if(!vec.empty() && vec.back() == b[j]){
                    j++;
                    continue;
                }
                vec.push_back(b[j++]);
            }
        }
        
        while(i < n){
            if(!vec.empty() && vec.back() == a[i]){
                i++;
                continue;
            }
            vec.push_back(a[i++]);
        }
        
        while(j < m){
            if(!vec.empty() && vec.back() == b[j]){
                j++;
                continue;
            }
            vec.push_back(b[j++]);
        }
        
        return vec;
        
    }
};
