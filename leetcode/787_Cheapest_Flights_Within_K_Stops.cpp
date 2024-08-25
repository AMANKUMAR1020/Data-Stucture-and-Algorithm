class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> mat(n);
        for(auto& f : flights){
            mat[f[0]].push_back({f[1],f[2]});
        }
        vector<vector<int>> dist(n, vector<int>(k+2,INT_MAX));

        using T = tuple<int,int,int>;
        priority_queue<T,vector<T>,greater<>> minHeap;

        dist[src][k+1]=0;
        minHeap.push({dist[src][k+1],src,k+1});

        while(!minHeap.empty()){
            const auto [d,u,stops] = minHeap.top();
            minHeap.pop();

            if(u == dst) return d;
            if(stops == 0) continue;
            for(auto& [v,w] : mat[u]){
                if(d + w < dist[v][stops - 1]){
                    dist[v][stops - 1] = d+w;
                    minHeap.emplace(dist[v][stops - 1], v, stops - 1);
                }
            }
        }
        return -1;
    }
};





/*
class Solution {
 public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,int k) {
    vector<vector<pair<int, int>>> graph(n);

    for (const vector<int>& flight : flights) {
      const int u = flight[0];
      const int v = flight[1];
      const int w = flight[2];
      graph[u].emplace_back(v, w);
    }

    return dijkstra(graph, src, dst, k);
  }

 private:
  int dijkstra(const vector<vector<pair<int, int>>>& graph, int src, int dst,int k) {
    vector<vector<int>> dist(graph.size(), vector<int>(k + 2, INT_MAX));
    using T = tuple<int, int, int>;  // (d, u, stops)
    priority_queue<T, vector<T>, greater<>> minHeap;

    dist[src][k + 1] = 0;
    minHeap.emplace(dist[src][k + 1], src, k + 1);

    while (!minHeap.empty()) {
      const auto [d, u, stops] = minHeap.top();
      minHeap.pop();
      if (u == dst)
        return d;
      if (stops == 0)
        continue;
      for (const auto& [v, w] : graph[u])
        if (d + w < dist[v][stops - 1]) {
          dist[v][stops - 1] = d + w;
          minHeap.emplace(dist[v][stops - 1], v, stops - 1);
        }
    }

    return -1;
  }
};
*/
