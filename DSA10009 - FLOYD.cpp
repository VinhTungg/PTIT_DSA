#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, n, m;
vector<vector<int>> adj;

int main(){
    boost;
        cin >> n >> m;
        adj.resize(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i != j) adj[i][j] = 1e9;
            }
        }
        for (int i = 0; i < m; ++i) {
            int x, y, z;
            cin >> x >> y >> z;
            adj[x][y] = adj[y][x] = z;
        }
        for (int i = 1; i <= n; ++i) 
            for (int j = 1; j <= n; ++j) 
                for (int z = 1; z <= n; ++z) 
                    adj[j][z] = min(adj[j][z], adj[i][j] + adj[i][z]);
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        cout << adj[a][b] << endl;
    }
}