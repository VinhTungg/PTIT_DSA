#include <bits/stdc++.h>
#define ll long long
#define boost cin.tie(0) -> sync_with_stdio(0)
#define time cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, n, m;
vector<vector<int>> adj;
vector<int> vs;

void DFS(int u) {
    vs[u] = 1;
    for (auto &v : adj[u]) {
        if (!vs[v]) {
            DFS(v);
        }
    }
}

int tplt(int u) {
    int cnt = 0;
    fill(vs.begin(), vs.end(), 0);
    vs[u] = 1;
    for (int i = 1; i <= n; ++i) {
        if (!vs[i]) {
            ++cnt;
            DFS(i);
        }
    }
    return cnt;
}

int main() {
    boost;
    //cin >> t;
    while (t--) {
        cin >> n >> m;
        adj.resize(n + 1);
        vs.assign(n + 1, 0);
        int u, v;
        for (int i = 0; i < m; ++i) {
            cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        for (int i = 1; i <= n; ++i) {
            cout << tplt(i) << endl;
        }
    }
    time;
}