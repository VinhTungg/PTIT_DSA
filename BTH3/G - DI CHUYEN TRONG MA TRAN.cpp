#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1;

int main(){
    boost;
    cin >> t;
    while(t--){
        int m, n;
        cin >> m >> n;
        vector<vector<int>> a(m + 1, vector<int>(n + 1)), b(m + 1, vector<int>(n + 1, 1));
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                cin >> a[i][j];
            }
        }
        queue<pair<pair<int, int>, int>> q;
        q.push({{1, 1}, 0});
        b[1][1] = 0;
        int res = 1e9;
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int step = q.front().second;
            q.pop();
            if(i == m && j == n){
                res = min(res, step);
            }
            if(i + a[i][j] <= m && b[i + a[i][j]][j] == 1){
                q.push({{i + a[i][j], j}, step + 1});
                b[i + a[i][j]][j] = 0;
            }
            if(j + a[i][j] <= n && b[i][j + a[i][j]] == 1){
                q.push({{i, j + a[i][j]}, step + 1});
                b[i][j + a[i][j]] = 0;
            }
        }
        if(res != 1e9) cout << res << endl;
        else cout << "-1\n";
    }
}