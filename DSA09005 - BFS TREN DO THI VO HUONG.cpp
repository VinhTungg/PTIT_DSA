#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
vector<vector<int>> ke;
bool visited[1005];

void BFS(int tar){
    queue<int> q;
    q.push(tar);
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        cout << tmp << ' ';
        visited[tmp] = true;
        for(auto &x : ke[tmp]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        int v, e, u;
        cin >> v >> e >> u;
        ke.resize(v + 1);
        memset(visited, false, sizeof(visited));
        for(int i = 0; i < e; ++i){
            int a, b;
            cin >> a >> b;
            ke[a].push_back(b);
            ke[b].push_back(a);
        }
        BFS(u);
        cout << endl;
        for(int i = 1; i <= v; ++i) ke[i].clear();
    }
}