#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, ok;
vector<vector<int>> edge;
vector<bool> visited;

bool DFS(int u, int par){
    visited[u] = true;
    for(int v : edge[u]){
        if(!visited[v]){
            if(DFS(v, u)) return true;
        }
        else if(v != par){
            return true;
        }
    }
    return false;
}

int main(){
    boost;
    cin >> t;
    while(t--){
        int n; cin >> n;
        int a, b;
        edge.clear();
        edge.resize(n + 1, vector<int>());
        visited.assign(n + 1, false);
        int cnt = n - 1;
        while(cnt--){
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        int ok = 1;
        for(int i = 1; i <= n; ++i){
            if(!visited[i]){
                if(DFS(i, -1)){
                    ok = 0;
                    break;
                }
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}