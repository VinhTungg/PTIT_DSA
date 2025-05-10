#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1;
vector<int> adj[1005];

void DFS(int u, vector<bool> &visited){
    visited[u] = true;
    for(auto v : adj[u]){
        if(!visited[v]) DFS(v, visited);
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        for(int i = 0; i < 1005; ++i) adj[i].clear();
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < m; ++i){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n + 1, false);
        int cnt = 0;
        for(int i = 1; i <= n; ++i){
            if(!visited[i]){
                cnt++;
                DFS(i, visited);
            }
        }
        cout << cnt << endl;
    }
}