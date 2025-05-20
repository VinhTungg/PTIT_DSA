#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, n, maxLev;
vector<vector<int>> adj;

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n;
        int u, v;
        adj.resize(n + 1);
        for (int i = 1; i <= n; ++i) adj[i].clear();
        for (int i = 0; i < n - 1; ++i) {
            cin >> u >> v;
            adj[u].emplace_back(v);
        }
        vector<int> dist(n + 1, -1);
        queue<int> q;
        dist[1] = 0;
        q.push(1);
        maxLev = 0;
        while (q.size()) {
            int top = q.front();
            q.pop();
            for (auto &v : adj[top]) {
                if (dist[v] == -1) {
                    dist[v] = dist[top] + 1;
                    // cerr << v << ' ' << top << ' ' << dist[v] << endl;
                    maxLev = max(maxLev, dist[v]);
                    q.push(v);
                }
            }
        }
        cout << maxLev << endl;
    }
}