#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
// TARJAN

int t = 1, n, m, timer;
vector<vector<int>> edge;
vector<int> disc, low;
vector<bool> visited;
set<int> ans;

void DFS(int u, int par){
    visited[u] = true;
    disc[u] = low[u] = ++timer;
    int children = 0;
    for(auto &v : edge[u]){
        if(v == par) continue;
        if(!visited[v]){
            DFS(v, u);
            ++children;
            low[u] = min(low[u], low[v]);
            if(par != -1 and disc[u] <= low[v]){
                ans.insert(u);
            }
        }else{
            low[u] = min(low[u], disc[v]);
        }
    }
    if(par == -1 and children > 1){
        ans.insert(u);
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n >> m;
        edge.clear();
        disc.clear();
        low.clear();
        ans.clear();
        edge.assign(n + 5, vector<int>());
        disc.assign(n + 5, 0);
        low.assign(n + 5, 0);
        visited.assign(n + 5, false);
        while(m--){
            int a, b;
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        timer = 0;
        for(int i = 1; i <= n; ++i){
            if(!visited[i]) DFS(i, -1);
        }
        for(auto &i : ans) cout << i << ' ';
        cout << endl;
    }
}