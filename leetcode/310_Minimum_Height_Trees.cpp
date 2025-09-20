class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] <= 1) {
                q.push(i);
            }
        }

        while (n > 2) {
            int sz = q.size();
            n -= sz;
            for (int i = 0; i < sz; i++) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if (--indegree[v] == 1) {
                        q.push(v);
                    }
                }
            }
        }

        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }

        return result;
    }
};