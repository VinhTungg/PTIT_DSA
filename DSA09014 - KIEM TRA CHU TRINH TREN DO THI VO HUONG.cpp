#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n, m;
vector<vector<int>> edge;
vector<int> parent;
vector<bool> visited;

/*
bool DFS(int u, int par){
    visited[u] = true;
    for(int v : edge[u]){
        if(!visited[v]){
            DFS(v, u);
        }else if(v != par){
            return true;
        }
    }
    return false;
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n >> m;
        edge.clear();
        edge.assign(n + 1, vector<int>());
        visited.assign(n + 1, false);
        while(m--){
            int a, b;
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        int ok = 0;
        for(int i = 1; i <= n; ++i){
            if(!visited[i]){
                if(DFS(i, -1)){
                    ok = 1;
                    break;
                }
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
*/

// DSU

void init(){
    for(int i = 1; i <= n; ++i) parent[i] = i;
}

int Find(int u){
    if(u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}

bool Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if(u == v) return false;
    parent[v] = u;
    return true;
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n >> m;
        edge.resize(n + 1, vector<int>());
        parent.resize(n + 1);
        visited.assign(n + 1, false);
        init();
        int check = 0;
        while(m--){
            int a, b;
            cin >> a >> b;
            if(!Union(a, b)) check = 1;
        }
        cout << (check ? "YES\n" : "NO\n");
    }
}