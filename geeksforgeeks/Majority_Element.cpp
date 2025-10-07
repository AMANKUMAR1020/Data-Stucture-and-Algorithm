class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        
        for(int a : arr)
            mp[a]++;

        for(pair<int,int> a : mp)
            if(a.second > n/2)
                return a.first;
        return -1;
    }
};
