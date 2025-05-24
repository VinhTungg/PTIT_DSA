#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, n, m, k, fre;
struct Point {
    int x, y, z, t;
    bool operator < (const Point &other) const {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        if (z != other.z) return z < other.z;
        return t < other.t;
    }
};
map<Point, int> fence;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
vector<vector<int>> a(105, vector<int>(105, 0));
vector<vector<int>> check(105, vector<int>(105, 0));

void dfs(int i, int j) {
    check[i][j] = 1;
    if (a[i][j]) ++fre;
    for (int k = 0; k < 4; ++k) {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (i1 >= 1 and i1 <= n and j1 >= 1 and j1 <= n and !fence[{i, j, i1, j1}] and !check[i1][j1]) {
            // cerr << i << " " << j << " " << i1 << " " << j1 << endl;
            dfs(i1, j1);
        }
    }
}

int main() {
    boost;
    //cin >> t;
    while (t--) {
        cin >> n >> k >> m;
        for (int i = 0; i < m; ++i) {
            int x, y, z, t;
            cin >> x >> y >> z >> t;
            fence[{x, y, z, t}] = 1;
            fence[{z, t, x, y}] = 1;
        }
        for (int i = 0; i < k; ++i) {
            int u, v;
            cin >> u >> v;
            a[u][v] = 1;
        }
        vector<int> res;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (a[i][j] and !check[i][j]) {
                    fre = 0;
                    dfs(i, j);
                    res.push_back(fre);
                }
            }
        }
        int sum = 0;
        for (int &x : res) sum += x;
        sum = sum * (sum - 1) >> 1;
        for (int &x : res) sum -= x * (x - 1) >> 1;
        cout << sum << endl;
    }
}