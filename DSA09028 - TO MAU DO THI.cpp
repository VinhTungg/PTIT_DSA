// Created by Vĩnh Tùng siêu cấp đẹp trai on 4/5/2025.
#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, v, e, m, ok;
vector<vector<int>> adj;
vector<int> color;

void DFS(int u, int cnt = 1) {
    if (!ok) return;
    for (auto &v : adj[u]) {
        if (!color[v]) {
            color[v] = 1;
            DFS(v, 1);
        }else{
            ++cnt;
            if(cnt > m) ok = 0;
        }
    }
}

int main() {
    boost;
    cin >> t;
    while (t--) {
        cin >> v >> e >> m;
        adj.assign(v + 1, vector<int>());
        color.assign(v + 1, 0);
        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        ok = 1;
        for (int i = 1; i <= v; i++) {
            if (!color[i]) {
                color[i] = 1;
                DFS(i);
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}
