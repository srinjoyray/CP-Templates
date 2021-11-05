// const int N=1e6;
vector<int> adj[N],visited(N),ans; 

void dfs(int node) {
    visited[node] = 1;
    for (int child : adj[node]) {
        if (!visited[child])
            dfs(child);
    }
    ans.push_back(node);
}

void topological_sort(int n) {
    visited.assign(n, 0);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}