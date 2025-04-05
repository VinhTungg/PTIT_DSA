#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
vector<vector<int>> ke;
vector<int> parent, res;
vector<bool> visited;

void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        for(auto &x : ke[tmp]){
            if(!visited[x]){
                parent[x] = tmp;
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        int v, e, u, tar;
        cin >> v >> e >> u >> tar;
        ke.assign(v + 1, vector<int>());
        parent.assign(v + 1, -1);
        visited.assign(v + 1, false);
        res.clear();
        for(int i = 1; i <= e; ++i){
            int a, b;
            cin >> a >> b;
            ke[a].push_back(b);
        }
        BFS(u);
        if(!visited[tar]){
            cout << "-1\n";
            continue;
        }
        for(int i = tar; i != -1; i = parent[i]) res.push_back(i);
        reverse(res.begin(), res.end());
        for(auto &x : res) cout << x << ' ';
        cout << endl;
    }
}