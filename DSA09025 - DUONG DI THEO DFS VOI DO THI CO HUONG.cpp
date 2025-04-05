#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
vector<vector<int>> a;
vector<int> parent, res, visited;

void DFS(int u){
    visited[u] = true;
    for(auto &x : a[u]){
        if(!visited[x]){
            parent[x] = u;
            DFS(x);
        }
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        int v, e, u, tar;
        cin >> v >> e >> u >> tar;
        a.assign(v + 1, vector<int>());
        parent.assign(v + 1, -1);
        visited.assign(v + 1, false);
        res.clear();
        for(int i = 1; i <= e; ++i){
            int b, c;
            cin >> b >> c;
            a[b].push_back(c);
        }
        DFS(u);
        if(!visited[tar]){
            cout << "-1\n";
            continue;
        }
        for(int cur = tar; cur != -1; cur = parent[cur]){
            res.push_back(cur);
        }
        for(int i = res.size() - 1; i >= 0; --i) cout << res[i] << ' ';
        cout << endl;
    }
}