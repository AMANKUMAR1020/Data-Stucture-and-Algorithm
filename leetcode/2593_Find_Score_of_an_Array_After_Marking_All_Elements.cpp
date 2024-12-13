#define ll long long

class Solution {
public:
    long long findScore(vector<int>& nums) {
        ll score = 0;
        int n = nums.size();
        vector<pair<int,int>> vec;
        unordered_map<int,int> 

        for(int i=0; i<n; i++)
        vec.push_back({nums[i], i});
        
        sort(vec.begin(), vec.end());
        
        for(int i=0; i<n; i++){
            if(mp.find(vec[i].first) == mp.end() && nums[vec[i].second] != INT_MAX){
                if(vec[i].second-1 >= 0) nums[vec[i].second - 1] = INT_MAX;
                if(vec[i].second+1 <  n) nums[vec[i].second + 1] = INT_MAX;
                score += vec[i].first;
            }
        }
        return score;
    }
};
