#include <bits/stdc++.h>
#define ll long long
#define boost cin.tie(0) -> sync_with_stdio(0)
#define time cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, n, m, maxLen;
vector<vector<int>> adj;

void DFS(int u, vector<int> &vs, int len) {
    maxLen = max(maxLen, len);
    for (auto &v : adj[u]) {
        if (!vs[v]) {
            // cerr << v << ' ';
            vs[v] = 1;
            DFS(v, vs, len + 1);
            vs[v] = 0;
        }
    }
}

int main() {
    boost;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int u, v;
        adj.resize(n + 1);
        for (int i = 0; i < m; ++i) {
            cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        vector<int> vs(n, 0);
        maxLen = 0;
        for (int i = 0; i < n; ++i) {
            fill(vs.begin(), vs.end(), 0);
            vs[i] = 1;
            // cerr << i << ' ';
            DFS(i, vs, 0);
        }
        cout << maxLen << endl;
        for (int i = 0; i <= n; ++i) adj[i].clear();
    }
    time;
}