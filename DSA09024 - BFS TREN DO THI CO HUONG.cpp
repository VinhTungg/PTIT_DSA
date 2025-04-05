#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
vector<int> ke[1005];
bool visited[1005];

void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    cout << u << ' ';
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        for(auto &x : ke[tmp]){
            if(!visited[x]){
                cout << x << ' ';
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
        int v, e, u;
        cin >> v >> e >> u;
        for(int i = 1; i <= e; ++i){
            int a, b;
            cin >> a >> b;
            ke[a].push_back(b);
        }
        memset(visited, false, sizeof(visited));
        BFS(u);
        for(int i = 1; i <= 1000; ++i) ke[i].clear();
        cout << endl;
    }
}