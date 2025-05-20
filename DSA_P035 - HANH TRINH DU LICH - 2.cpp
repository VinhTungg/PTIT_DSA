#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, n, m, k;
const ll INF = (ll)4e18;

// dp bitmask kết hợp dijkstra


int main(){
    boost;
    //cin >> t;
    while(t--){
        cin >> n >> m >> k;
        vector<int> needPoint(k + 1);
        for (int i = 1; i <= k; ++i) cin >> needPoint[i];
        vector<vector<pair<int, int>>> adj(n + 1);
        needPoint[0] = 1;
        for (int i = 0; i < m; ++i) {
            int u, v, c;
            cin >> u >> v >> c;
            adj[u].emplace_back(v, c);
        }
        // Chạy dijkstra ở mỗi điểm cần thêm
        vector<vector<ll>> dist(k + 1, vector<ll> (k + 1, INF));
        for (int i = 0; i <= k; ++i) {
            vector<ll> d(n + 1, INF);
            priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
            d[needPoint[i]] = 0;
            pq.push({0, needPoint[i]});
            while (pq.size()) {
                auto [du, u] = pq.top(); pq.pop();
                if (du > d[u]) continue;
                for (auto &e : adj[u]) {
                    int v = e.first;
                    ll w = e.second;
                    if (d[v] > du + w) {
                        d[v] = du + w;
                        pq.push({d[v], v});
                    }
                }
            }
            for (int j = 0; j <= k; ++j) {
                dist[i][j] = d[needPoint[j]];
            }
        }
        for (int i = 0; i <= k; ++i)
            for (int j = 0; j <= k; ++j)
                if (dist[i][j] == INF) {
                    cout << -1;
                    return 0;
                }
        int MAX = 1 << k;
        static ll dp[1 << 15][16];
        for (int mask = 0; mask < MAX; ++mask) {
            for (int i = 0; i <= k; ++i) {
                dp[mask][i] = INF;
            }
        }
        dp[0][0] = 0;
        for (int mask = 0; mask < MAX; ++mask) {
            for (int i = 0; i <= k; ++i) {
                ll cur = dp[mask][i];
                if (cur == INF) continue;
                for (int j = 0; j < k; ++j) {
                    if (mask & (1 << j)) continue;
                    int newMask = mask | (1 << j);
                    ll cost = dist[i][j + 1];
                    dp[newMask][j + 1] = min(dp[newMask][j + 1], cur + cost);
                }
            }
        }
        ll ans = INF;
        for (int i = 0; i <= k; ++i) {
            ans = min(ans, dp[MAX - 1][i] + dist[i][0]);
        }
        cout << (ans >= (INF >> 1) ? -1 : ans);
    }
}