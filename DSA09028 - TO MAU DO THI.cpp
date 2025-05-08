// Created by Vĩnh Tùng siêu cấp đẹp trai on 4/5/2025.
#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, v, e, m;
vector<vector<int>> adj;
vector<int> color;

bool isSafe(int u, int c){
    for(auto &v : adj[u]){
        if(color[v] == c) return false;
    }
    return true;
}

bool graphColoringUtil(int u){
    if(u > v) return true;
    for(int c = 1; c <= m; c++){
        if(isSafe(u, c)){
            color[u] = c;
            if (graphColoringUtil(u + 1)) return true;
            color[u] = 0;
        }
    }
    return false;
}

int main(){
    boost;
    cin >> t;
    while (t--){
        cin >> v >> e >> m;
        adj.assign(v + 1, vector<int>());
        color.assign(v + 1, 0);
        for(int i = 0; i < e; i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        } 
        cout << (graphColoringUtil(1) ? "YES" : "NO") << endl;
    }
}
