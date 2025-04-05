#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
vector<vector<int>> edge;
vector<bool> visited;

void BFS(int i){
    queue<int> q;
    visited[i] = true;
    q.push(i);
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        for(auto &x : edge[tmp]){
            if(!visited[x]){
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
        int n, m;
        cin >> n >> m;
        edge.clear();
        edge.resize(n + 10, vector<int>());
        visited.assign(n + 10, false);
        while(m--){
            int a, b;
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        int cnt = 0;
        for(int i = 1; i <= n; ++i){
            if(!visited[i]){
                BFS(i);
                ++cnt;
            }
        }
        cout << cnt << endl;
    }
}