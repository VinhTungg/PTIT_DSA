#include <bits/stdc++.h>
#define ll long long
#define boost cin.tie(0) -> sync_with_stdio(0)
#define time cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, st, en, stop;
const int MIN = -1000, MAX = 1000;
int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[] = {-2, -1, 1, 2, -2, -1, 1, 2};
set<pair<int, int>> s, vs;

int BFS(int i, int j) {
    vs.insert({i, j});
    queue<pair<pair<int, int>, int>> q;
    q.push({{i, j}, 0});
    int dis = MAX;
    while (q.size()) {
        auto tmp = q.front();
        q.pop();
        if (tmp.first.first == st and tmp.first.second == en) dis = min(dis, tmp.second);
        for (int k = 0; k < 8; ++k) {
            int i1 = tmp.first.first + dx[k], j1 = tmp.first.second + dy[k];
            if (i1 >= MIN and i1 <= MAX and j1 >= MIN and j1 <= MAX and !vs.count({i1, j1}) and !s.count({i1, j1})) {
                q.push({{i1, j1}, tmp.second + 1});
                vs.insert({i1, j1});
            }
        }
    }
    return (dis == MAX ? -1 : dis);
}

int main() {
    boost;
    cin >> t;
    while (t--) {
        s.clear();
        cin >> st >> en >> stop;
        for (int i = 0; i < stop; ++i) {
            int u, v;
            cin >> u >> v;
            s.insert({u, v});
        }
        if (s.count({st, en}) or s.count({0, 0})) {
            cout << -1 << endl;
            continue;
        }
        cout << BFS(0, 0) << endl;
    }
    time;
}