#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
/*
int t = 1, n, m, s;
vector<int> ke[1001];
vector<pair<int, int>> dscanh;
vector<bool> visited;


void DFS(int u, int s, int t){
    visited[u] = true;
    for (auto i : ke[u]) {
        if((u == s and i == t) or (u == t and i == s)) continue;
        if (!visited[i]) {
            DFS(i, s, t);
        }
    }
}

int tplt(int s, int t){
    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        if(!visited[i]){
            ++cnt;
            DFS(i, s, t);
        }
    }
    return cnt;
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n >> m;
        visited.assign(n + 1, false);
        dscanh.clear();
        for(int i = 1; i <= n; ++i) ke[i].clear();
        while(m--){
            int u, v;
            cin >> u >> v;
            ke[u].push_back(v);
            ke[v].push_back(u);
            dscanh.push_back({u, v});
        }
        for(int i = 1; i <= n; ++i) sort(ke[i].begin(), ke[i].end());
        int cc = tplt(0, 0);
        for(auto &i : dscanh){
            int x = i.first, y = i.second;
            fill(visited.begin(), visited.end(), false);
            if(tplt(x, y) > cc){
                cout << x << ' ' << y << ' ';
            }
        }
        cout << endl;
    }
}
*/

// TARJAN
int t = 1, n, m, timer;
vector<vector<int>> edge;
vector<int> disc, low;
vector<bool> visited;
vector<pair<int, int>> vp;

void DFS(int u, int par){
    visited[u] = true;
    disc[u] = low[u] = ++timer;
    for(int v : edge[u]){
        if(v == par) continue;
        if(!visited[v]){
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            if(disc[u] < low[v]){
                if(u < v) vp.push_back({u, v});
                else vp.push_back({v, u});
            }
        }else{
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n >> m;
        edge.assign(n + 10, vector<int>());
        disc.assign(n + 10, 0);
        low.assign(n + 10, 0);
        visited.assign(n + 10, false);
        vp.clear();
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
        sort(vp.begin(), vp.end(),[](pair<int, int> a, pair<int, int> b){
            return (a.first != b.first ? a.first < b.first : a.second < b.second);
        });
        for(auto &x : vp) cout << x.first << ' ' << x.second << ' ';
        cout << endl;
    }
}