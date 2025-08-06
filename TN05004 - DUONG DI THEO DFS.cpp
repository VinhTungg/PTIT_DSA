#include <bits/stdc++.h>
#define ll long long
#define boost cin.tie(0) -> sync_with_stdio(0)
#define time cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, n, m, start;
vector<vector<int>> adj;
vector<int> vs, parent;

void DFS(int u) {
    vs[u] = 1;
    for (int &v : adj[u]) {
        if (!vs[v]) {
            parent[v] = u;
            DFS(v);
        }
    }
}

int main() {
    boost;
    cin >> t;
    while (t--) {
        cin >> n >> m >> start;
        int u, v;
        adj.resize(n + 1);
        vs.assign(n + 1, 0);
        parent.assign(n + 1, -1);
        for (int i = 0; i < m; ++i) {
            cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        DFS(start);
        for (int i = 1; i <= n; ++i) {
            if (i != start) {
                int tmp = i;
                stack<int> st;
                while (parent[tmp] != -1) {
                    st.push(tmp);
                    tmp = parent[tmp];
                }
                st.push(start);
                if (st.size() == 1) {
                    cout << "No path\n"; 
                    continue;
                }
                while (st.size()) {
                    cout << st.top() << ' ';
                    st.pop();
                } 
                cout << endl;
            }
        }
        for (int i = 1; i <= n; ++i) adj[i].clear();
    }
    time;
}