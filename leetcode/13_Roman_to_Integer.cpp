#include <unordered_map>
#include <string>

class Solution {
public:
    int romanToInt(const std::string& s) { 
        std::unordered_map<char, int> mp = {
            {'I', 1}, {'V', 5}, {'X', 10}, 
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int n = s.size();
        int num = mp[s[n - 1]]; // Start with the last character's value

        for (int i = n - 2; i >= 0; i--) {
            if (mp[s[i]] < mp[s[i + 1]]) {
                num -= mp[s[i]]; // Subtract if the current value is less than the next one
            } else {
                num += mp[s[i]]; // Otherwise, add it
            }
        }
        
        return num;
    }
};

