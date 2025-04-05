#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n, m;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char a[1005][1005];

void dfs(int x, int y, int n, int m, char a[][1005]){
    a[x][y] = '.'; // mark as visited
    for(int i = 0; i < 4; ++i){
        int u = x + dx[i];
        int v = y + dy[i];
        if(u >= 1 && u <= n && v >= 1 && v <= m && a[u][v] == '#') dfs(u, v, n, m, a);
    }
}

int main(){
    boost;
    //cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) cin >> a[i][j];
        int cnt = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(a[i][j] == '#'){
                    dfs(i, j, n, m, a);
                    ++cnt;
                }
            }
        }
        cout << cnt;
    }
}