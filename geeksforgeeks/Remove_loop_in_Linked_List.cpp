class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for(string& str : operations){
            ans += (str == "--X" || str == "X--") ? -1 : 1;
        }
        return ans;
    }
};
