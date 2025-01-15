#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

int main() {
    int N, M;
    cin >> N >> M;

    // Vertex weights
    vector<ll> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    // Graph representation (adjacency list)
    vector<vector<pii>> adj(N + 1);

    // Reading edges
    for (int i = 0; i < M; ++i) {
        int u, v;
        ll b;
        cin >> u >> v >> b;
        adj[u].emplace_back(v, b);
        adj[v].emplace_back(u, b);
    }

    // Dijkstra's algorithm to find minimum path weights
    vector<ll> dist(N + 1, LLONG_MAX);  // dist[i] stores the minimum path weight to vertex i
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[1] = A[1];  // Starting point, dist[1] = A[1]
    pq.push({dist[1], 1});  // {distance, vertex}

    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // If this distance is not the current known minimum, skip it
        if (d > dist[u]) continue;

        // Traverse all neighbors of vertex u
        for (auto &edge : adj[u]) {
            int v = edge.first;
            ll weight = edge.second;

            ll new_dist = d + weight + A[v];  // Path weight to vertex v

            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }

    // Output the results for vertices 2 to N
    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}
