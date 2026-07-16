class Solution {
  public:
    int ans = INT_MAX;
    void dfs(int ptr, string &source, vector<string> &words, unordered_map<string, bool> &mp, string &target, int cnt){
        
        if(source == target) {
            ans = min(ans, cnt + 1);
            return;
        }
        
        if(mp[source])  return;
            
        mp[source] = true;

        for(int i=0; i<source.size(); i++){
            string temp = source;
            
            for(char c = 'a'; c <= 'z'; c++){
                temp[i] = c;
                
                if(mp.find(temp) != mp.end() && mp[temp] == false){
                    dfs(i, temp, words, mp, target, cnt + 1);
                }
            }
        }
        mp[source] = false;
    }
    
    int wordLadder(vector<string> &words, string &s, string &e) {
        int n = words.size();

        unordered_map<string, bool> mp;
        
        for(string str : words) mp[str] = false;

        for(int i=0; i<s.size(); i++){
            string temp = s;
            
            for(char c = 'a'; c <= 'z'; c++){
                temp[i] = c;
                
                if(mp.count(temp) && mp[temp] == false)
                    dfs(i, temp, words, mp, e, 1);
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

