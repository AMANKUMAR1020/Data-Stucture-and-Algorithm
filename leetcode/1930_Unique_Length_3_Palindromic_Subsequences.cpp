class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int ans = 0;
        for(char c = 'a'; c <= 'z'; c++){
            int f = -1, l = -1;
            for(int i = 0; i<n; i++){
                if(s[i] == c){
                    if(f == -1)
                        f = i;
                    else
                        l = i;
                }
            }
            unordered_set<string> st;
            for(int i = f + 1; i<l; i++){
                string str = "";
                str += s[f] + s[i] + s[l];
                st.insert(str);
            }
            ans += st.size();
        }
        return ans;
    }
};


/*
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;

        // Try every possible character 'a' to 'z' as the outer character
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            int first = -1, last = -1;

            // Find first and last occurrence of the character ch
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == ch) {
                    if (first == -1) first = i;
                    last = i;
                }
            }

            if (first != -1 && last != -1 && last - first > 1) {
                unordered_set<char> middle_chars;
                for (int i = first + 1; i < last; ++i) {
                    middle_chars.insert(s[i]);
                }
                ans += middle_chars.size(); // All combinations ch + x + ch
            }
        }

        return ans;
    }
};


class Solution {
public:
    int countPalindromicSubsequence(string s) {
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
            bool flag = true;
            if(temp[0] != temp[2])
                flag = false;
            
            if(flag)
                cnt++;
        }
        for(auto m : mp){
            cout<<m.first<<" "<<m.second<<" "<<endl;
        }
        return cnt;
    }
    void dp(string &s, string str, unordered_map<string,int> &mp, int i, int n){

        if(i>=n){return;}

        if(str.size()==3){
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
