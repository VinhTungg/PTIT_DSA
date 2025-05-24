#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, n;
vector<int> parent, sz;

double distance(pair<double, double> a, pair<double, double> b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

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
    cin >> t;
    while (t--) {
        cin >> n;
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        init();
        vector<pair<double, double>> P(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> P[i].first >> P[i].second;
        }
        double ans = 0;
        vector<pair<double, pair<int, int>>> dis;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                dis.push_back({distance(P[i], P[j]), {i, j}});
            }
        }
        sort(dis.begin(), dis.end());
        for (auto e : dis) {
            if (Union(e.second.first, e.second.second)) {
                ans += e.first;
            }
        }
        cout << fixed << setprecision(6) << ans << endl;
    }
}