// class Solution {
//   public:
//     int solve(string& s, int k){
//         if(k <= 0)
//             return 0;
//         int n = s.size();
//         int ans = 0;
//         int j=0;
        
//         vector<int> vec(26,0);
//         unordered_set<int> st;
        
//         for(int i=0; i<n; i++){
//             vec[s[i] - 'a']++;
//             st.insert(s[i]);
//             while(j < i && st.size() > k){
//                 if(--vec[s[j] - 'a'] == 0)
//                     st.erase(s[j]);
//                 j++;
//             }
//             ans += (i - j + 1);
//         }
//         return ans;
//     }
//     int countSubstr(string& s, int k) {
//         return solve(s,k) - solve(s, k-1);
//     }
// };


class Solution {
public:
    int countAtMost(string& s, int k) {
        if (k < 0) return 0;
        vector<int> freq(26, 0);
        int distinct = 0;
        long long ans = 0;
        int l = 0;

        for (int r = 0; r < (int)s.size(); r++) {
            int c = s[r] - 'a';
            if (freq[c]++ == 0) distinct++;

            while (distinct > k) {
                int cl = s[l] - 'a';
                if (--freq[cl] == 0) distinct--;
                l++;
            }

            ans += (r - l + 1);
        }
        return (int)ans;
    }

    int countSubstr(string& s, int k) {
        return countAtMost(s, k) - countAtMost(s, k - 1);
    }
};


/*
Key idea
If you can compute:

countAtMost(k): number of substrings with at most k distinct characters
then `countExactly(k) = countAtMost(k) - countAtMost(k-1)
Both countAtMost can be done with a sliding window (two pointers).
*/



/*
        int n = s.size();
        int ans = 0;
        int i=0, j=0;
        
        vector<int> vec(26,0);
        unordered_set<int> st;
        
        for(int i=0; i<n; i++){

            vec[s[i] - 'a']++;
            
            while(j < i && st.size() > k){
                vec[s[j] - 'a']--;
                
                if(vec[s[j] - 'a'] == 0)
                    st.erase(s[j]);
                j++;
            }
            
            ans = max(ans, i - j);
        }
        return ans;

*/
