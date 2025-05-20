#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, n;
vector<vector<int>> adj;
vector<int> par;

void BFS() {
    queue<int> q;
    q.push(1);
    par.assign(n + 1, -1);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (auto &v : adj[u]) {
            if (par[v] == -1) {
                par[v] = u;
                q.push(v);
            }
        }
    }
}

void FindPath(int u) {
    vector<int> res;
    res.emplace_back(u);
    while (par[u] != -1) {
        u = par[u];
        res.emplace_back(u);
    }
    reverse(res.begin(), res.end());
    for (auto &x : res) cout << x << ' ';
    cout << endl;
}

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
        BFS();
        for (int i = 2; i <= n; ++i) {
            if (!adj[i].size()) FindPath(i); 
        }
    }
}