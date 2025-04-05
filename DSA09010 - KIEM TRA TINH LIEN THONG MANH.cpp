#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n, m;
vector<vector<int>> edge, reedge;
vector<bool> visited;

int DFS(int i, const vector<vector<int>> &a){
    visited[i] = true;
    int cnt = 1;
    for(auto &x : a[i]){
        if(!visited[x]){
            visited[x] = true;
            cnt += DFS(x, a);
        }
    }
    return cnt;
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n >> m;
        edge.clear();
        reedge.clear();
        edge.resize(n + 1, vector<int>());
        reedge.resize(n + 1, vector<int>());
        while(m--){
            int a, b;
            cin >> a >> b;
            edge[a].push_back(b);
            reedge[b].push_back(a);
        }
        visited.assign(n + 1, false);
        int ok = DFS(1, edge);
        if(ok != n){
            cout << "NO\n";
            continue;
        }
        visited.assign(n + 1, false);
        ok = DFS(1, reedge);
        if(ok != n){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
}