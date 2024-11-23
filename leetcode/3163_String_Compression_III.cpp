class Solution {
public:
    string compressedString(string word) {
        int n = word.length();
        if (n == 0) return "";  // Handle empty string
        
        string str = "";
        int count = 1;  // Use integer for count
        for (int i = 1; i < n; i++) {
            if (word[i] == word[i - 1]) {
                if(count==9){
                    str += to_string(count) + word[i - 1];  // Add previous character and its count
                    count = 0;  // Reset count for the new character
                }
                count++;
            } else {
                str += to_string(count) + word[i - 1];  // Add previous character and its count
                count = 1;  // Reset count for the new character
            }
        }
        
        // Add the last character and its count
        str += to_string(count) + word[n - 1];
        
        return str;
    }
};







class Solution {
public:
    string compressedString(string word) {
        string comp = "";

        // pos tracks our position in the input string
        int pos = 0;

        // Process until we reach end of string
        while (pos < word.length()) {
            int consecutiveCount = 0;

            char currentChar = word[pos];

            // Count consecutive occurrences (maximum 9)
            while (pos < word.length() && consecutiveCount < 9 &&
                   word[pos] == currentChar) {
                consecutiveCount++;
                pos++;
            }

            // Append count followed by character to result
            comp += to_string(consecutiveCount) + currentChar;
        }

        return comp;
    }
};
