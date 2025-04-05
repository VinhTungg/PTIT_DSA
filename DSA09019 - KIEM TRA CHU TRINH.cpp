#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n, m;
vector<vector<int>> edge;
vector<bool> visited;

bool DFS(int u, int par){
    visited[u] = true;
    for(int v : edge[u]){
        if(!visited[v]){
            if(DFS(v, u)) return true;
        }else if(v != par) return true;
    }
    return false;
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n >> m;
        edge.clear();
        edge.resize(1005, vector<int>());
        visited.assign(1005, false);
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
                    ok = 1; break;
                }
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}