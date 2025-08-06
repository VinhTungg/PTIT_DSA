#include <bits/stdc++.h>
#define ll long long
#define boost cin.tie(0) -> sync_with_stdio(0)
#define time cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, n, m, st;
vector<vector<int>> adj;
vector<int> vs, path;

void DFS(int u) {
    vs[u] = 1;
    path.emplace_back(u);
    for (int &v : adj[u]) {
        if (!vs[v]) {
            DFS(v);
        }
    }
}

int main() {
    boost;
    cin >> t;
    while (t--) {
        cin >> n >> m >> st;
        int u, v;
        adj.resize(n + 1);
        vs.assign(n + 1, 0);
        for (int i = 0; i < m; ++i) {
            cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        DFS(st);
        cout << "DFS(" << st << ") = ";
        for (int i = 0; i < path.size(); ++i) cout << path[i] << (i != path.size() - 1 ? " -> " : "\n");
        for (int i = 1; i <= n; ++i) adj[i].clear();
        path.clear();
    }
    time;
}