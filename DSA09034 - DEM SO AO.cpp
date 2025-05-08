#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, n, m;
vector<vector<char>> adj;
vector<vector<bool>> visited;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void DFS(int i, int j){
    visited[i][j] = true;
    for(int k = 0; k < 8; ++k){
        int next_i = i + dx[k], next_j = j + dy[k];
        if(next_i >= 1 and next_i <= n and next_j >= 1 and next_j <= m and adj[next_i][next_j] == 'W' and !visited[next_i][next_j]){
            DFS(next_i, next_j);
        }
    }
}   



int main(){
    boost;
    //cin >> t;
    while(t--){
        cin >> n >> m;
        adj.assign(n + 1, vector<char>(m + 1));
        visited.assign(n + 1, vector<bool>(m + 1, false));
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                cin >> adj[i][j];
            }
        }
        int cnt = 0;        
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(adj[i][j] == 'W' and !visited[i][j]){
                    DFS(i, j);
                    ++cnt;
                }
            }
        }
        cout << cnt;
    }
}