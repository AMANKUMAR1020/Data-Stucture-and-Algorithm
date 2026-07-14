class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<int> dist(V,INT_MAX);
        vector<vector<pair<int, int>>> graph(V);
        
        int n = edges.size();

        for(int i=0; i<n; i++){
            graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()){
            auto [w, u] = pq.top(); pq.pop();
            
            if(dist[u] < w)
                continue;
            
            for(auto [v , wt] : graph[u]){
                
                if(w + wt < dist[v]){
                    dist[v] = w + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};










/*
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<int> dist(V,INT_MAX);
        vector<vector<int>> graph(V);
        
        int n = edges.size();

        for(int i=0; i<n; i++){
            graph[edges[i][0]].push_back( edges[i][1] );
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()){
            auto [w, u] = pq.top(); pq.pop();
            
            if(dist[u] > w)
                continue;
            
            for(int v : graph[u]){
                // if(dist[v] == INT_MAX){
                    if(dist[u] + w < dist[v]){
                        dist[v] = w + dist[u];
                        pq.push({dist[v], v});
                    }
                // }
            }
        }
        return dist;
    }
};





class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<int> dist(V,INT_MAX);
        vector<vector<pair<int,int>>> graph(V);
        vector<vector<int>> w(V,vector<int>(0,V));
        
        int n = edges.size();
        // int m = edges[0].size();
        
        for(int i=0; i<n; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            graph[u].push_back({v, w});
            graph[v].push_back({v, w});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()){
            auto temp = pq.top(); pq.pop();
            int d = temp.first;
            int u = temp.second;
            
            if(d > dist[u])
                continue;
            
            for(auto neighbour : graph[u]){
                int v = neighbour.first;
                int w = neighbour.second;
                
                if(dist[v] == INT_MAX){
                    if(dist[u] + w < dist[v]){
                        dist[v] = w + dist[u];
                        pq.push({dist[v], v});
                    }
                }
            }
        }
        return dist;
    }
};


*/
