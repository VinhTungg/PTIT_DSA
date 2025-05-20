#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, n, m, maxDays, seeds;
vector<vector<int>> vs(505, vector<int>(505)), a(505, vector<int>(505));
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

struct Point {
    int x, y, fre;
};
queue<Point> q;

int BFS() {
    while (q.size()) {
        auto [x, y, fre] = q.front();
        q.pop();
        // cerr << x << ' ' << y << endl;
        maxDays = max(maxDays, fre);
        for (int k = 0; k < 4; ++k) {
            int nextX = x + dx[k], nextY = y + dy[k];
            if (~nextX and nextX < n and ~nextY and nextY < m and a[nextX][nextY] and !vs[nextX][nextY]) {
                q.push({nextX, nextY, fre + 1});
                vs[nextX][nextY] = 1;
                --seeds;
            }
        }
    }
    return seeds ? -1 : maxDays;
}

int main() {
    boost;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        seeds = 0;
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < m; ++j) {
                vs[i][j] = 0;
                cin >> a[i][j];
                if (a[i][j] == 2) {
                    q.push({i, j, 0});
                    vs[i][j] = 1;
                }
                else if (a[i][j] == 1) ++seeds;
            }
        maxDays = 0;
        cout << BFS() << endl;
        // cerr << endl;
    }
}