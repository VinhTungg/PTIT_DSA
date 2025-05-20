#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, n, m, cnt, val;
vector<vector<int>> adj;
vector<int> vs;

int BFS(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, 0});
    vs[i] = 1;
    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        for (auto &v : adj[top.first]) {
            if (!vs[v]) {
                vs[v] = 1;
                if (v == j) return top.second + 1;
                q.push({v, top.second + 1});
            }
        }
    }
    return -1;
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n >> m;
        adj.resize(n + 1);
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
        }
        cnt = val = 0;
        vs.assign(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i != j) {
                    int tmp = BFS(i, j);
                    if (tmp != -1) {
                        val += tmp;
                        ++cnt;
                    }
                    fill(vs.begin(), vs.end(), 0);
                }
            }
        }
        cout << setprecision(2) << fixed << 1.0 * val / cnt << endl;
        for (int i = 1; i <= n; ++i) adj[i].clear();
    }
}