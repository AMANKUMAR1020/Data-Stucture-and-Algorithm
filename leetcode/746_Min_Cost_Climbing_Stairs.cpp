class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n+1, -1);
        return min(res(0, n, memo, cost),res(1, n, memo, cost));
    }
private:
    int res(int i, int n, vector<int>& memo, vector<int>& cost){
        if(i >= n)
            return 0;
        if(memo[i] != -1)
            return memo[i];
        int temp1 = res(i+1, n, memo, cost);
        int temp2 = res(i+2, n, memo, cost);
        memo[i] = cost[i] + min(temp1, temp2);
        return memo[i];
    }
};

/*
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n, -1);
        return min(dfs(0, cost, memo), dfs(1, cost, memo));
    }

private:
    int dfs(int i, const vector<int>& cost, vector<int>& memo) {
        int n = cost.size();
        if (i >= n) return 0;

        if (memo[i] != -1) return memo[i];

        int takeOne = dfs(i + 1, cost, memo);
        int takeTwo = dfs(i + 2, cost, memo);
        memo[i] = cost[i] + min(takeOne, takeTwo);
        return memo[i];
    }
};

*/
