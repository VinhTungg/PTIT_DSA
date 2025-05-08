#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, V, E;
vector<int> adj[15];
bool visited[15];

bool hamiltonianPath(int u, int count) {
    if (count == V) return true;
    for (auto &v : adj[u]) {
        if (!visited[v]) {
            visited[v] = true;
            if (hamiltonianPath(v, count + 1))
                return true;
            visited[v] = false;
        }
    }
    return false;
}

int hasHamiltonianPath() {
    for (int i = 1; i <= V; i++) {
        memset(visited, 0, sizeof(visited));
        visited[i] = true;
        if (hamiltonianPath(i, 1))
            return 1;
    }    
    return 0;
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> V >> E;
        for (int i = 1; i <= V; i++)
            adj[i].clear();
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout << (hasHamiltonianPath() ? 1 : 0) << endl;
    }
}
