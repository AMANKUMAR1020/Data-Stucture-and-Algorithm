class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int n = s.size();
        int ans = 0;
        int i=0, j=0;
        
        vector<int> vec(26,0);

        for(int i=0; i<n; i++){

            vec[s[i] - 'a']++;
            
            while(j < i && vec[s[i] - 'a'] > 1){
                vec[s[j] - 'a']--;
                j++;
            }
            
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
