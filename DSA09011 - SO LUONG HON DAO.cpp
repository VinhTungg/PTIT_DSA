#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n, m;
vector<vector<int>> edge, visited;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void DFS(int i, int j){
    visited[i][j] = 1;
    for(int k = 0; k < 8; ++k){
        int next_i = i + dx[k], next_j = j + dy[k];
        if(next_i >= 1 and next_i <= n and next_j >= 1 and next_j <= m and edge[next_i][next_j] == 1 and !visited[next_i][next_j]){
            DFS(next_i, next_j);
        }
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n >> m;
        edge.resize(501, vector<int>(501));
        visited.assign(501, vector<int>(501, 0));
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                cin >> edge[i][j];
            }
        } 
        int cnt = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(edge[i][j] and !visited[i][j]){
                    ++cnt;
                    DFS(i, j);
                }
            }
        }
        cout << cnt << endl;
    }
}