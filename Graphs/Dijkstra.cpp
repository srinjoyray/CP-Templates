// single-source shortest paths
const ll INF = 1e18;
vector<vector<pair<int, long long>>> adj(N); //{v,wt}
vector<long long> dist(N),path(N);
void dijkstra(int source) {
    
    dist.assign(N, INF);
    path.assign(N, -1);

    dist[source] = 0;
    set<pair<long long, long long>> q;
    q.insert({0, source});
    while (!q.empty()) {
        int node = (*q.begin()).second;
        q.erase(q.begin());

        for (auto edge : adj[node]) {
            int to = edge.first;
            long long len = edge.second;

            if (dist[node] + len < dist[to]) {
                q.erase({dist[to], to});
                dist[to] = dist[node] + len;
                path[to] = node;
                q.insert({dist[to], to});
            }
        }
    }
}