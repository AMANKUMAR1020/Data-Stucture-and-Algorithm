class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> vec(26,0);
        int n = s.size();
        for(int i=0; i<n; i++){
            vec[s[i] - 'a']++;
        }
        for(int i=0; i<n; i++){
            if(vec[s[i] - 'a']==1)
                return i;
        }
        return -1;
    }
};©leetcode