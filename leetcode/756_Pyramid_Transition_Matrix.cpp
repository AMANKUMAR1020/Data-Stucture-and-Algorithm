#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        // Build mapping: pair -> possible tops
        unordered_map<string, vector<char>> mp;
        for (string &triple : allowed) {
            mp[triple.substr(0, 2)].push_back(triple[2]);
        }
        unordered_map<string, bool> memo;
        return dfs(bottom, mp, memo);
    }

private:
    bool dfs(string bottom, unordered_map<string, vector<char>>& mp,
             unordered_map<string, bool>& memo) {
        if (bottom.size() == 1) return true;
        if (memo.count(bottom)) return memo[bottom];

        vector<string> nextRows;
        buildNextRows(bottom, mp, 0, "", nextRows);

        for (string &row : nextRows) {
            if (dfs(row, mp, memo)) {
                return memo[bottom] = true;
            }
        }
        return memo[bottom] = false;
    }

    void buildNextRows(string &bottom, unordered_map<string, vector<char>>& mp,
                       int idx, string current, vector<string>& nextRows) {
        if (idx == bottom.size() - 1) {
            nextRows.push_back(current);
            return;
        }
        string key = bottom.substr(idx, 2);
        if (!mp.count(key)) return;
        for (char c : mp[key]) {
            buildNextRows(bottom, mp, idx + 1, current + c, nextRows);
        }
    }
};
