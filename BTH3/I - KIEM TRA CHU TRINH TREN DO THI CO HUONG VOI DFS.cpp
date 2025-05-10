#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1;
vector<vector<int>> g(1005);
vector<int> color(1005);

bool DFS(int u){
    color[u] = 1;
    for(auto v : g[u]){
        if(!color[v] and DFS(v)) return true;
        else if(color[v] == 1) return true;
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
        g.clear();
        g.resize(n + 1, vector<int>());
        fill(color.begin(), color.end(), 0);
        for(int i = 0; i < m; ++i){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
        }
        int ok = 0;
        for(int i = 1; i <= n; ++i){
            if(!color[i] and DFS(i)){
                ok = 1;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}