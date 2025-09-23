int MAXI = 100001;
class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        vector<bool> vec(MAXI,false);
        vector<int> ans;
        
        for(int& i : a) vec[i]=true;
        for(int& i : b) vec[i]=true;
        for(int i=0; i<MAXI; i++) 
            if(vec[i]) 
                ans.push_back(i);
        return ans;
    }
};
