class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        unordered_map<int,bool> mp;
        for(int a : arr){
            int temp = target - a;
            if(mp.find(temp) != mp.end())
                return true;
            mp[a]=true;
        }
        return false;
    }
};
