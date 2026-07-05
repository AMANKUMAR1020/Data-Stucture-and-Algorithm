class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        vector<int> vec(26,0);
        unordered_set<char> st;
        int i=0, j=0;
        int n = s.size();
        int ans = -1;
        
        while(i < n){
            
            vec[s[i] - 'a']++;
            st.insert(s[i]);
            
            while(j < i && k < st.size()){
                vec[s[j] - 'a']--;
                
                if(vec[s[j] - 'a'] == 0)
                    st.erase(s[j]);
                j++;
            }
            ans = max(ans, i - j + 1);
            
            i++;
        }
        
        return st.size() < k ? -1 : ans;
    }
};
