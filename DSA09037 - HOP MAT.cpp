#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, people, vertex, edge;
vector<int> People, vs;
vector<vector<int>> adj;

void DFS(int u){
    vs[u] = 1;
    for(auto &v : adj[u]){
        if(!vs[v]) DFS(v);
    }
}

int check(int u){
    vs.assign(vertex + 1, 0);
    DFS(u);
    for(int &x : People)
        if(!vs[x]) return 0;
    return 1;
}

int main(){
    boost;
    // cin >> t;
    while(t--){
        cin >> people >> vertex >> edge;
        adj.resize(vertex + 1);
        while(people--){
            int x; cin >> x;
            People.emplace_back(x);
        }
        for(int i = 1; i <= edge; ++i){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        int meeting = 0;
        for(int i = 1; i <= vertex; ++i){
            meeting += check(i);
        }
        cout << meeting;
    }
}