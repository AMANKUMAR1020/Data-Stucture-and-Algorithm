class Solution {
public:
    int minLength(string s) {
        int n = s.size();
        string ans="";

        for(int i=0; i<n; i++){

            ans += s[i];

            int j = ans.size();

            if( j > 1 && (( ans[j-2] == 'A' && ans[j-1] == 'B') || (ans[j-2] == 'C' && ans[j-1] == 'D')) ){
                // cout<<ans<<'\n';

                string temp ="";
                int k = 0;

                while(k < j - 2) temp += ans[k++];

                ans  = temp;
                // cout<<temp<<'\n';
            }
        }
        return ans.size();
    }
};
