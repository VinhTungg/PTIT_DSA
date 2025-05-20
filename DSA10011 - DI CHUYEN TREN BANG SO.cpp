#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, n, m;
vector<vector<int>> adj, a;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int dijkstra() {
    adj[1][1] = a[1][1];
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    q.push({0, {1, 1}});
    while (!q.empty()) {
        int l = q.top().first;
        int i = q.top().second.first;
        int j = q.top().second.second;
        q.pop();
        if (l > adj[i][j]) continue;
        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni >= 1 and ni <= n and nj >= 1 and nj <= m) {
                if (adj[ni][nj] > adj[i][j] + a[ni][nj]) {
                    adj[ni][nj] = adj[i][j] + a[ni][nj];
                    q.push({adj[ni][nj], {ni, nj}});
                }
            }
        }
    }
    return adj[n][m];
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n >> m;
        a.resize(505, vector<int> (505));
        adj.assign(505, vector<int> (505, 1e9));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) cin >> a[i][j];
        }
        cout << dijkstra() << endl;
    }
}