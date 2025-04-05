// Created by Vĩnh Tùng siêu cấp đẹp trai on 4/5/2025.
#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n, m, flag;
vector<vector<int>> adj;
vector<int> color;

void DFS(int u) {
    if (!flag) return;
    for (auto &v : adj[u]) {
        if (!color[v]) {
            color[v] = 3 - color[u];
            DFS(v);
        }else if (color[v] == color[u]) {
            flag = 0;
        }
    }
}

int main() {
    boost;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        adj.assign(n + 1, vector<int>());
        color.assign(n + 1, 0);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        flag = 1;
        for (int i = 1; i <= n; i++) {
            if (!color[i]) {
                color[i] = 1;
                DFS(i);
            }
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
}