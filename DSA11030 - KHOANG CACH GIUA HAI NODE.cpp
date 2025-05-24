#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, n;
const int LOGN = 10;
vector<vector<int>> adj;
vector<int> depth;
int parent[LOGN][1005];

void DFS(int u, int p) {
    parent[0][u] = p;
    for (int v : adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        DFS(v, u);
    }
}

int LCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int an = 0; an < LOGN; ++an) {
        if (diff & (1 << an)) u = parent[an][u];
    }
    if (u == v) return u;
    for (int an = LOGN - 1; ~an; --an) {
        if (parent[an][u] != parent[an][v]) {
            u = parent[an][u];
            v = parent[an][v];
        }
    }
    return parent[0][u];
}

int main() {
    boost;
    cin >> t;
    while (t--) {
        cin >> n;
        adj.resize(n + 1);
        depth.assign(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            adj[i].clear();
            for (int j = 0; j < LOGN; ++j) {
                parent[j][i] = 0;
            }
        }
        int u, v;
        for (int i = 0; i < n - 1; ++i) {
            cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        DFS(1, 0);
        for (int ances = 1; ances < LOGN; ++ances) {
            for (int u = 1; u <= n; ++u) {
                parent[ances][u] = parent[ances - 1][parent[ances - 1][u]];
            }
        }
        int query;
        cin >> query;
        while (query--) {
            cin >> u >> v;
            int w = LCA(u, v);
            // cerr << w << ' ';
            cout << depth[u] + depth[v] - (depth[w] << 1) << endl;
        }
    }
}