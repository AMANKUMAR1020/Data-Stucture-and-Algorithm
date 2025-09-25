#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        vector<long long> v;
        v.reserve(n);

        for (int x : nums) v.push_back(llabs((long long)x));

        sort(v.begin(), v.end());

        long long ans = 0;
        int r = 0;
        for (int l = 0; l < n; ++l) {
            if (r < l + 1) r = l + 1;
            while (r < n && 2 * v[l] >= v[r]) ++r;
            ans += (r - l - 1); // all indices in (l, r) are valid with l
        }
        return ans;
    }
};
©leetcode
