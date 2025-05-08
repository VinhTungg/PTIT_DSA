#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
vector<int> adj[1005];
bool visited[1005];
vector<pair<int, int>> spanning_tree;

void dfs(int u, int parent) {
    visited[u] = true;
    if(parent) spanning_tree.push_back({parent, u});
    for(int v : adj[u]){
        if(!visited[v]){
            dfs(v, u);
        }
    }
}

void solve() {
    int n, m, start;
    cin >> n >> m >> start;
    for(int i = 1; i <= n; ++i){
        adj[i].clear();
        visited[i] = false;
    }
    spanning_tree.clear();
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(start, 0);
    if(spanning_tree.size() == n - 1){
        for(auto &edge : spanning_tree){
            cout << edge.first << " " << edge.second << endl;
        }
    }else cout << -1 << endl;
}

int main() {
    boost;
    cin >> t;
    while (t--){
        solve();
    }
}