class Solution {
public:
    int maxDifference(string s) {
        int odd = 0;
        int even = INT_MAX;
        unordered_map<char,int> mp;

        for(char c : s)
        mp[c]++;

        for(auto m : mp)
            if(m.second%2)
                odd = max(odd,m.second);
            else
                even = min(even,m.second);

        return odd - even;
    }
};
