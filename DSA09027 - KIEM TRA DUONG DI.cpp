#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
vector<vector<int>> ke;
vector<int> visited;

void DFS(int i){
    visited[i] = 1;
    for(auto &x : ke[i]){
        if(!visited[x]) DFS(x);
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        ke.assign(n + 1, vector<int>());
        for(int i = 0; i < m; ++i){
            int a, b;
            cin >> a >> b;
            ke[a].push_back(b);
            ke[b].push_back(a);
        }
        int q; cin >> q;
        while(q--){
            visited.assign(n + 1, 0);
            int st, tar;
            cin >> st >> tar;
            DFS(st);
            cout << (visited[tar] ? "YES\n" : "NO\n");
        }
    }
}