#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, n;
vector<vector<char>> a;
vector<vector<int>> vs;
pair<int, int> st, en;

struct Point {
    int x, y, dis;
};

int BFS() {
    queue<Point> q;
    q.push({st.first, st.second, 0});
    while (q.size()) {
        auto [x, y, fre] = q.front();
        q.pop();
        if (x == en.first and y == en.second) return fre;
        for (int i = x + 1; i < n; ++i) {
            if (a[i][y] != 'X' and !vs[i][y]) {
                q.push({i, y, fre + 1});
                vs[i][y] = 1;
            } else break;
        }
        for (int i = x - 1; ~i; --i) {
            if (a[i][y] != 'X' and !vs[i][y]) {
                q.push({i, y, fre + 1});
                vs[i][y] = 1;
            } else break;
        }
        for (int i = y + 1; i < n; ++i) {
            if (a[x][i] != 'X' and !vs[x][i]) {
                q.push({x, i, fre + 1});
                vs[x][i] = 1;
            } else break;
        }
        for (int i = y - 1; ~i; --i) {
            if (a[x][i] != 'X' and !vs[x][i]) {
                q.push({x, i, fre + 1});
                vs[x][i] = 1;
            } else break;
        }
    }
    return -1;
}

int main() {
    boost;
    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(100, vector<char>(100));
        vs.assign(100, vector<int>(100, 0));
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < n; ++j) cin >> a[i][j];
        cin >> st.first >> st.second >> en.first >> en.second;
        cout << BFS() << endl;
    }
}