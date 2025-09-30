class Solution {
public:
    bool wordBreak(string s, vector<string>& word) {
        int n = s.size();
        unordered_set<string> st(word.begin(), word.end());
        queue<int> qu; qu.push(0);
        vector<bool> visited(n+1, false);
        int ind=0;

        while(!qu.empty()){
            ind = qu.front(); qu.pop();
            if(visited[ind])
                continue;
                visited[ind] = true;

            for(int start = ind+1; start <=n; start++){
                string str = s.substr(ind, start-ind);
                if(st.count(str) == 1){
                    if (start == n) return true;
                    qu.push(start);
                }
            }
        }
        return false;
    }
};

// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& word) {
//         int n = s.size();
//         unordered_set<string> st(word.begin(), word.end());
//         vector<bool> dp(n+1, false);
//         dp[0] = true;
        
//         for(int i=0; i<=n; i++){
//             for(int j=0; j<i; j++){
//                 string str = s.substr(j, i - j);
//                 if(dp[j] && st.count(str) != 0){
//                     //cout<<i<<" "<<j<<" "<<str<<endl;
//                     dp[i] = true;
//                     break;
//                 }
//             }
//         }
//         return dp[s.size()];
//     }
// };
