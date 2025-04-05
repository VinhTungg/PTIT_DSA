#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n, m;
vector<vector<char>> adj;

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n >> m;
        pair<int, int> start, end;
        adj.assign(n + 1, vector<char>(m + 1, '0'));
        // cin.ignore();
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                cin >> adj[i][j];
                if(adj[i][j] == 'S') start = {i, j};
                if(adj[i][j] == 'T') end = {i, j};
            }
        }
        bool visited[n + 1][m + 1][4][3]; //[i][j][direction][step]
        memset(visited, 0, sizeof(visited));
        queue<pair<pair<int, int>, pair<int, int>>> q;
        /*
            Với direction = 0: đi lên
            direction = 1: sang phải
            direction = 2: đi xuống
            direction = 3: sang trái 
            step ta có tối đa 2 lần ngoặt 
        */
        for(int i = 0; i < 4; ++i){
            q.push({start, {i, 0}});
            visited[start.first][start.second][i][0] = 1;
        }
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        bool flag = 0;
        while(!q.empty()){
            auto tmp = q.front().first;
            int direction = q.front().second.first;
            int step = q.front().second.second;
            q.pop();
            if(tmp == end){
                flag = 1;
                break;
            }
            for(int i = 0; i < 4; ++i){
                int i1 = tmp.first + dx[i];
                int j1 = tmp.second + dy[i];
                if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && adj[i1][j1] != '*' && !visited[i1][j1][direction][step]){
                    if(i != direction){
                        if(step < 2){
                            q.push({{i1, j1}, {i, step + 1}});
                            visited[i1][j1][i][step + 1] = 1;
                        }
                    }
                    else{
                        q.push({{i1, j1}, {i, step}});
                        visited[i1][j1][i][step] = 1;
                    }
                }
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
}