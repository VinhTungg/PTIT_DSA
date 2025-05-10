#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1;
vector<int> disc, low;
vector<bool> visited;
vector<vector<int>> g;
vector<bool> cut;
int timer = 0;

void DFS(int u, int par){
    disc[u] = low[u] = timer++;
    visited[u] = true;
    int child = 0;
    for(auto v : g[u]){
        if(v == par) continue;
        if(visited[v]){
            low[u] = min(low[u], disc[v]);
        }
        else{
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= disc[u] and par != -1){
                cut[u] = true;
            }
            ++child;
        }
    }
    if(par == -1 and child > 1){
        cut[u] = true;
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        g.clear();
        g.resize(n + 1, vector<int>());
        disc.assign(n + 1, 0);
        low.assign(n + 1, 0);
        visited.assign(n + 1, false);
        cut.assign(n + 1, false);
        for(int i = 0; i < m; ++i){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int i = 1; i <= n; ++i){
            if(!visited[i]) DFS(i, -1);
        }
        for(int i = 1; i <= n; ++i){
            if(cut[i]) cout << i << " ";
        }
        cout << endl;
    }
}