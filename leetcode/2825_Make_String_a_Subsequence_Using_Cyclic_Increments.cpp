class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int i = 0, j = 0;

        while (i < n && j < m) {
            // Calculate the next character in a cyclic manner
            char nextChar = (str1[i] == 'z') ? 'a' : str1[i] + 1;

            // Check if the current character or the next cyclic character matches
            if (str1[i] == str2[j] || nextChar == str2[j]) {
                j++;
            }
            i++;
        }

        // If we have traversed all characters of str2, return true
        return j == m;
    }
};
