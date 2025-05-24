#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, vertex, edge;
vector<int> parent, sz;

void init() {
    for (int i = 1; i <= vertex; ++i) parent[i] = i;
}

int Find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}

bool Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u == v) return false;
    if (sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    parent[v] = u;
    return true;
}

struct Point {
    int u, v, w;
};

int main() {
    boost;
    cin >> t;
    while (t--) {
        cin >> vertex >> edge;
        parent.resize(vertex + 1);
        sz.assign(vertex + 1, 1);
        init();
        vector<Point> adj(edge);
        for (int i = 0; i < edge; ++i) {
            cin >> adj[i].u >> adj[i].v >> adj[i].w;
        }
        sort(adj.begin(), adj.end(), [](Point a, Point b) {
            return a.w < b.w;
        });
        int mst_weight = 0;
        for (int i = 0; i < edge; ++i) {
            if (Union(adj[i].u, adj[i].v)) {
                mst_weight += adj[i].w;
            }
        }
        cout << mst_weight << endl;
    }
}