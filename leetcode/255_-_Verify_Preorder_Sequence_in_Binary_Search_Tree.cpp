// OJ: https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool verifyPreorder(vector<int>& A) {
        stack<int> s;
        int mn = INT_MIN;
        for (int n : A) {
            if (n < mn) return false;
            while (s.size() && s.top() < n) {
                mn = s.top();
                s.pop();
            }
            s.push(n);
        }
        return true;
    }
};
