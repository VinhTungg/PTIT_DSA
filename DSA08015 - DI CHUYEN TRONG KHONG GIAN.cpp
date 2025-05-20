#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, a, b, c;
vector<vector<vector<char>>> cube, vs;
int dx[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};

struct Point {
    int x, y, z, fre;
};
Point st, en;

int BFS() {
    queue<Point> q;
    q.push({st.x, st.y, st.z, 0});
    while (q.size()) {
        auto [x, y, z, fre] = q.front();
        q.pop();
        // cerr << x << ' ' << y << ' ' << z << endl;
        if (x == en.x and y == en.y and z == en.z) return fre;
        for (int k = 0; k < 6; ++k) {
            int nX = x + dx[k], nY = y + dy[k], nZ = z + dz[k];
            if (~nX and nX < a and ~nY and nY < b and ~nZ and nZ < c and vs[nX][nY][nZ] == '0') {
                q.push({nX, nY, nZ, fre + 1});
                vs[nX][nY][nZ] = '1';
            }
        }
    }
    return -1;
}

int main() {
    boost;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        cube.resize(35, vector<vector<char>>(35, vector<char> (35)));
        vs.assign(35, vector<vector<char>>(35, vector<char> (35)));
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; ++j) {
                for (int k = 0; k < c; ++k) {
                    cin >> cube[i][j][k];
                    vs[i][j][k] = '0';
                    if (cube[i][j][k] == 'S') {
                        st.x = i, st.y = j, st.z = k;
                        vs[i][j][k] = '1';
                    }
                    else if (cube[i][j][k] == 'E') en.x = i, en.y = j, en.z = k;
                    if (cube[i][j][k] == '#') vs[i][j][k] = '1';
                }
            }
        }
        cout << BFS() << endl;
        // cerr << endl;
    }
}