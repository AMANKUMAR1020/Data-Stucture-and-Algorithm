class Solution {
 public:
  int distributeCookies(vector<int>& cookies, int k) {
    int ans = INT_MAX;
    dfs(cookies, 0, k, vector<int>(k), ans);
    return ans;
  }

 private:
  void dfs(const vector<int>& cookies, int s, int k, vector<int>&& children,
           int& ans) {
    if (s == cookies.size()) {
      ans = min(ans, ranges::max(children));
      return;
    }

    for (int i = 0; i < k; ++i) {
      children[i] += cookies[s];
      dfs(cookies, s + 1, k, std::move(children), ans);
      children[i] -= cookies[s];
    }
  }
};







// class Solution {
// public:
//     int distributeCookies(vector<int>& weights, int days) {
//         int n = weights.size();
//         int r = accumulate(weights.begin(), weights.end(), 0);
//         int l = *max_element(weights.begin(), weights.end());

//         while (l <= r) {
//             int mid = l + (r - l) / 2;
//             int requiredDays = countDays(weights, mid);
//             if (requiredDays <= days) {
//                 r = mid - 1; // Try to minimize the maximum load
//             } else {
//                 l = mid + 1; // Need more capacity
//             }
//         }
//         return l; // l is the minimum max load that fits in given days
//     }

// private:
//     int countDays(const vector<int>& weights, int maxLoad) {
//         int days = 1;
//         int sum = 0;
//         for (int w : weights) {
//             if (sum + w > maxLoad) {
//                 days++;
//                 sum = 0;
//             }
//             sum += w;
//         }
//         return days;
//     }
// };



/*
class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<int> prefixSum(n + 1, 0);
        // Compute prefix sums
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + cookies[i];
        }

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));
        
        // Base case: 0 cookies distributed to 0 children
        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, k); j++) {
                for (int l = j - 1; l < i; l++) {
                    // Calculate the number of cookies for the current child
                    int current = prefixSum[i] - prefixSum[l];
                    // Update dp[i][j] with the minimum maximum cookies
                    dp[i][j] = min(dp[i][j], max(dp[l][j - 1], current));
                }
            }
        }
        
        // Return the minimum maximum number of cookies
        return dp[n][k];
    }
};

*/
