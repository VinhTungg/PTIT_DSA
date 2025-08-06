#include <bits/stdc++.h>
#define ll long long
#define boost cin.tie(0) -> sync_with_stdio(0)
#define time cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, n, m, st, en;
vector<int> parent, vs;
vector<vector<int>> adj;

void BFS(int u) {
    vs[u] = 1;
    queue<int> q;
    q.push(u);
    while (q.size()) {
        int tmp = q.front();
        q.pop();
        if (tmp == en) break;
        for (int &v : adj[tmp]) {
            if (!vs[v]) {
                vs[v] = 1;
                parent[v] = tmp;
                q.push(v);
            }
        }
    }
}

int main() {
    boost;
    cin >> t;
    while (t--) {
        cin >> n >> m >> st >> en;
        adj.resize(n + 1);
        parent.assign(n + 1, -1);
        vs.assign(n + 1, 0);
        while (m--) {
            int u, v;
            cin >> u >> v;
            adj[u].emplace_back(v);
        }
        BFS(st);
        if (parent[en] == -1) {
            cout << -1 << endl;
        } else {
            vector<int> ans;
            while (parent[en] != -1) {
                ans.push_back(en);
                en = parent[en];
            }
            ans.push_back(st);
            reverse(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); ++i) cout << ans[i] << (i != ans.size() - 1 ? " -> " : "\n");
        }
        for (int i = 1; i <= n; ++i) adj[i].clear();
    }
    time;
}