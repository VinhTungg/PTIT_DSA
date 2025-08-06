#include <bits/stdc++.h>
#define ll long long
#define boost cin.tie(0) -> sync_with_stdio(0)
#define time cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, n, m, num;
vector<int> may_phat, dist; 

int main() {
    boost;
    //cin >> t;
    while (t--) {
        cin >> n >> num >> m;
        vector<vector<int>> adj(n);
        may_phat.resize(num);
        dist.assign(n, 1e9);
        pair<int, int> ans = {0, 0};
        int u, v;
        for (int &i : may_phat) cin >> i;
        for (int i = 0; i < m; ++i) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<pair<int, int>> q;
        for (int &i : may_phat) {
            dist[i] = 0;
            q.emplace(i, 0);
        }
        while (q.size()) {
            auto [u, dis] = q.front();
            q.pop();
            for (int &v : adj[u]) {
                if (dist[v] > dis + 1) {
                    dist[v] = dis + 1;
                    // cerr << v << ' ' << dist[v] << endl;
                    q.emplace(v, dist[v]);

                }
            } 
        }
        for (int i = 0; i < n; ++i) {
            if (ans.second < dist[i]) ans = {i, dist[i]};
        }
        cout << ans.first << endl;
    }
    time;
}