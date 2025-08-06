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
vector<int> parent, sz;
vector<vector<int>> adj;

void init() {
    for (int i = 1; i <= n; ++i) parent[i] = i;
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

int main() {
    boost;
    //cin >> t;
    while (t--) {

        cin >> n >> m >> st;
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        init();
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            Union(u, v);
        }
        st = Find(st);
        vector<int> ans;
        for (int i = 1; i <= n; ++i) {
            if (st != Find(i)) ans.push_back(i);
        }
        if (!ans.size()) cout << 0 << endl;
        else {
            for (auto &x : ans) cout << x << endl;
        }
    }
    time;
}