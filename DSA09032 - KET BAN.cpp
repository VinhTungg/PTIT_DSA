#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n, m, cnt;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent, sz;

/*
void DFS(int u){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            DFS(v);
            ++cnt;
        }
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n >> m;
        adj.assign(n + 1, vector<int>());
        visited.assign(n + 1, false);
        while(m--){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int ans = 0;
        cnt = 1;
        for(int i = 1; i <= n; ++i){
            if(!visited[i]){
                DFS(i);
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        cout << ans << endl;
    }
}
*/

// DSU

void init(){
    for(int i = 1; i <= n; ++i){
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int u){
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void Union(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return;
    if(sz[u] < sz[v]) swap(u, v);
    parent[v] = u;
    sz[u] += sz[v];
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n >> m;
        parent.assign(n + 1, 0);
        sz.assign(n + 1, 0);
        init();
        while(m--){
            int a, b;
            cin >> a >> b;
            Union(a, b);
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i) ans = max(ans, sz[i]);
        cout << ans << endl;
    }
}