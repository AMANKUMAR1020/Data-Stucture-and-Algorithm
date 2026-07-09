class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        int n = arr.size();

        for(int i=0; i<n; i++){
            string str = arr[i];
            sort(str.begin(), str.end());
            mp[str].push_back(arr[i]);
        }
        
        for(auto m : mp){
            // vector<string> temp;
            // for(int i : m.second){
            //     temp.push_back(arr[i]);
            // }
            // if(!temp.empty())
            //     ans.push_back(temp);
            ans.push_back(m.second);
        }
        
        return ans;
    }
};
