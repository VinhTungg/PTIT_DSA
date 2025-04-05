#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
vector<vector<int>> edge;
vector<int> color;

bool DFS(int u){
    color[u] = 1;
    for(int v : edge[u]){
        if(color[v] == 1) return true;
        if(!color[v] and DFS(v)) return true;
    }
    color[u] = 2;
    return false;
}

int main(){
    boost;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        edge.clear();
        edge.assign(n + 1, vector<int>());
        color.assign(n + 1, 0);
        while(m--){
            int a, b;
            cin >> a >> b;
            edge[a].push_back(b);
        }
        int ok = 0;
        for(int i = 1; i <= n; ++i){
            if(!color[i]){
                if(DFS(i)){
                    ok = 1;
                    break;
                }
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}