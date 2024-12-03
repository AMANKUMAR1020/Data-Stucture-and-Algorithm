class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size();
        int m = spaces.size();
        int j=0;
        string str="";

        sort(spaces.begin(), spaces.end());

        for(int i=0; i<n; i++){
            if(j < m && spaces[j] == i){
                str += " ";
                j++;
            }
            str += s[i];
        }
        return str;
    }
};
