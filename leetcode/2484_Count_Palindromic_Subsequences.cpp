class Solution {
 public:
  int countPalindromes(string s) {
    constexpr int kMod = 1'000'000'007;
    constexpr int kPatternSize = 5;
    long ans = 0;

    for (char a = '0'; a <= '9'; ++a)
      for (char b = '0'; b <= '9'; ++b) {
        const vector<char> pattern{a, b, '.', b, a};
        // dp[i] := the number of subsequences of pattern[i..n) in s, where
        // pattern[2] can be any character
        vector<long> dp(kPatternSize + 1);
        dp.back() = 1;
        for (const char c : s)
          for (int i = 0; i < kPatternSize; ++i)
            if (pattern[i] == '.' || pattern[i] == c)
              dp[i] += dp[i + 1];
        ans += dp[0];
        ans %= kMod;
      }

    return ans;
  }
};


/*
class Solution {
public:
    int countPalindromes(string s) {
        int n = s.size();
        unordered_map<string,int> mp;

        for(int i=0; i<n; i++){
            string str = "";
                str += s[i];
            dp(s,str,mp,i,n);
        }
        int cnt = 0;
        for(auto m : mp){

            string temp = m.first;
            int k = temp.size();
            bool flag = true;
            
            for(int i=0; i<=k/2; i++){
                if(temp[i] != temp[k-i-1]){
                    flag = false;
                    break;
                }
            }
            if(flag)
                cnt += m.second;
        }
        for(auto m : mp){
            cout<<m.first<<" "<<m.second<<" "<<endl;
        }
        return cnt;
    }
    void dp(string &s, string str, unordered_map<string,int> &mp, int i, int n){

        if(i>=n){return;}

        if(str.size()==5){
            mp[str]++;
            //cout<<mp[str]<<" ";
            return ;
        }

        if(mp.find(str) != mp.end()){
            return;
        }

        dp(s, str, mp, i+1, n);
        dp(s, str + s[i+1], mp, i+1, n);
    }
};
*/
