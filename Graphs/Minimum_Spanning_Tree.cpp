// Kruskal with Disjoint Set Union
struct UnionFind {
	int n;
	vector<int> rank;
	vector<int> parent;
	// store other info as required
	UnionFind(int n) {
		rank.resize(n+1);
		fill(rank.begin(), rank.end(), 0);
		parent.resize(n+1);
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}
	}
	int get(int a) {
		return parent[a] = (parent[a] == a ? a : get(parent[a]));
	}
	void merge(int a, int b) {
		a = get(a);
		b = get(b);
		if (a == b) {
			return;
		}
		if (rank[a] == rank[b]) {
			rank[a]++;
		}
		if (rank[a] > rank[b]) {
			parent[b] = a;
		} else {
			parent[a] = b;
		}
	}
};
struct Edge {
    int u, v, weight;
};
bool comp(struct Edge e1,struct Edge e2){
    return e1.weight<=e2.weight;
}
vector<Edge> edges;
void mst(int n){
    ll cost=0;
    vector<Edge> result;
    UnionFind u(n);

    sort(edges.begin(),edges.end(),comp);

    for (Edge e : edges) {
        if (u.get(e.u) != u.get(e.v)) {
            cost += e.weight;
            result.push_back(e);
            u.merge(e.u, e.v);
        }
    }

	// return cost if required
}


