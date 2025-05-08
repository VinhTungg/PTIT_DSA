#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n, m, last;
vector<int> adj[1005], parent(1005);
bool visited[1005];

void dfs(int u, int par){
    if(last) return;
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            parent[v] = u;
            dfs(v, u);
        }
        else{
            if(v != parent[u] and v == 1){
                last = u;
                return;
            }
        }
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= n; i++) adj[i].clear(), parent[i] = 0, visited[i] = false;
        for(int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for(int i = 1; i <= n; ++i) sort(adj[i].begin(), adj[i].end());
        last = 0;
        dfs(1, 0);
        if(last){
            vector<int> path;
            path.emplace_back(1);
            while(last != 1){
                path.emplace_back(last);
                last = parent[last];
            }
            path.emplace_back(1);
            reverse(path.begin(), path.end());
            for(int i : path) cout << i << ' ';
            cout << endl;
        }
        else cout << "NO" << endl;
    }
}