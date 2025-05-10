#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1;
vector<int> visited(1005), adj[1001];

void dfs(int u){
    visited[u] = 1;
    cout << u << " ";
    for(int v : adj[u]){
        if(!visited[v]) dfs(v);
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        int n, m, st; cin >> n >> m >> st;
        for(int i = 1; i <= n; ++i) adj[i].clear();
        for(int i = 0; i < m; ++i){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        fill(visited.begin(), visited.end(), 0);
        dfs(st);
        cout << endl;
    }
}