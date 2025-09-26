class Solution {
public:
    int lengthLongestPath(string input) {
        int ans = 0,i = 0;
        int n = input.size();
        unordered_map<int,int> mp;
        mp[0]=0;
        while(i<n){
            int depth = 0;
            while(i<n && input[i] == '\t'){
                depth++;
                i++;
            }
            bool file=false;
            int j=i;
            while(i<n && input[i] != '\n'){
                if(input[i] == '.')
                    file = true;
                i++;
            }
            int name = i - j;
            if(file){
                ans = max(ans, mp[depth] + name);
            }else{
                mp[depth+1] = mp[depth] + name + 1;
            }

            if(i<n && input[i] == '\n')
                i++;
        }
        return ans;
    }
};©leetcode
