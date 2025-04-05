#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
bool visited[1005];
vector<int> ke[1005];

void DFS(int tar){
    visited[tar] = true;
    cout << tar << ' ';
    for(auto &x : ke[tar]){
        if(!visited[x]){
            DFS(x);
        }
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        for(int i = 1; i <= 1000; ++i) ke[i].clear();
        int V, E, tar;
        cin >> V >> E >> tar;
        for(int i = 1; i <= E; ++i){
            int u, v;
            cin >> u >> v;
            ke[u].push_back(v);
            ke[v].push_back(u);
        }
        memset(visited, false, sizeof(visited));
        DFS(tar);
        cout << endl;
    }
}