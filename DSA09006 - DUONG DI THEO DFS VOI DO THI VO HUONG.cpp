#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
vector<vector<int>> edge;
vector<int> parent, visited;

void DFS(int u){
    visited[u] = 1;
    for(int v : edge[u]){
        if(!visited[v]){
            parent[v] = u;
            visited[v] = 1;
            DFS(v);
        }
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        int n, m, u, v;
        cin >> n >> m >> u >> v;
        edge.assign(n + 1, vector<int>());
        parent.assign(n + 1, 0);
        visited.assign(n + 1, 0);
        while(m--){
            int a, b;
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        DFS(u);
        vector<int> ans;
        while(parent[v]){
            ans.push_back(v);
            v = parent[v];
        }
        if(ans.size()){
            ans.push_back(v);
            reverse(ans.begin(), ans.end());
            for(auto &x : ans) cout << x << ' ';
        }else cout << "-1";
        cout << endl;
    }
}