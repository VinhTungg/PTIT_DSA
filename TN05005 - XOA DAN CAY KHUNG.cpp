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

int main() {
    boost;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int u, v;
        vector<vector<int>> adj(n + 1);
        vector<int> deg(n + 1, 0), dist(n + 1, 0);

        for (int i = 0; i < n - 1; ++i) {
            cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
            ++deg[u];
            ++deg[v];
        }
        queue<pair<int, int>> q;
        for (int i = 1; i <= n; ++i) {
            if (deg[i] == 1) {
                dist[i] = 1;
                q.emplace(i, 1);
            }
        }
        while (q.size()) {
            auto [u, dis] = q.front();
            q.pop();
            for (auto &v : adj[u]) {
                if (!dist[v]) {
                    --deg[v];
                    if (deg[v] == 1) {
                        dist[v] = dis + 1;
                        q.emplace(v, dis + 1);
                    }
                }
            }
        }
        ll res = 0;
        for (int i = 1; i <= n; ++i) {
            if (!dist[i] or dist[i] > m) ++res;
        }
        cout << res << endl;
    }
    time;
}