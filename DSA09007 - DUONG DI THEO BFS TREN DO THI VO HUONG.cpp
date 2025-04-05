#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
vector<vector<int>> edge;
vector<int> parent, visited;

void BFS(int i){
    queue<int> q;
    q.push(i);
    visited[i] = 1;
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        for(int &x : edge[tmp]){
            if(!visited[x]){
                q.push(x);
                parent[x] = tmp;
                visited[x] = 1;
            }
        }
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        int n, m, u, v;
        cin >> n >> m >> u >> v;
        edge.clear();
        edge.resize(n + 1, vector<int>());
        parent.assign(n + 1, 0);
        visited.assign(n + 1, 0);
        while(m--){
            int a, b;
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        BFS(u);
        vector<int> ans;
        while(parent[v] != 0){
            ans.push_back(v);
            v = parent[v];
        }
        if(ans.size()){
            ans.push_back(v);
            reverse(ans.begin(), ans.end());
            for(auto &x : ans) cout << x << ' ';
        }else cout << "-1";
        cout << endl;
    }
}