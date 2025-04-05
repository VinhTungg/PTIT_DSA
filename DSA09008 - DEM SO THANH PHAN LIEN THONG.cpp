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


void DFS(int i){
    visited[i] = true;
    for(auto &x : edge[i]){
        if(!visited[x]){
            DFS(x);
        }
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n >> m;
        edge.clear();
        edge.resize(n + 10, vector<int>());
        visited.assign(n + 10, false);
        while(m--){
            int u, v;
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        int cnt = 0;
        for(int i = 1; i <= n; ++i){
            if(!visited[i]){
                ++cnt;
                DFS(i);
            }
        }
        cout << cnt << endl;
    }
}


//  DSU NOT AC

/*
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
    else{
        if(u < v) parent[v] = u;
        else parent[u] = v;
        return true;
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n >> m;
        parent.clear();
        parent.resize(n + 10);
        init();
        while(m--){
            int a, b;
            cin >> a >> b;
            Union(a, b);
        }
        int cnt = 0;
        for(int i = 1; i <= n; ++i) {
            if(Find(i) == i) ++cnt;
        }
        cout << cnt << endl;
    }
}
*/