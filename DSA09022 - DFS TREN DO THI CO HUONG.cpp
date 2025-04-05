#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
vector<int> a[1005];
bool visited[1005];

void DFS(int u){
    cout << u << ' ';
    visited[u] = true;
    for(auto &x : a[u]){
        if(!visited[x]){
            DFS(x);
        }
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        int v, e, u;
        cin >> v >> e >> u;
        for(int i = 1; i <= e; ++i){
            int b, c;
            cin >> b >> c;
            a[b].push_back(c);
        }
        memset(visited, false, sizeof(visited));
        DFS(u);
        for(int i = 1; i <= 1000; ++i) a[i].clear();
        cout << endl;
    }
}