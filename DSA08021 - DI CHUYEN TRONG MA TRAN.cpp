#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n, m, res = 1e9;
int a[1005][1005]{}, b[1005][1005];

void BFS(int i, int j){
    b[1][1] = 0;
    queue<tuple<int, int, int>> q;
    q.push({i, j, 0});
    while(!q.empty()){
        auto tmp = q.front();
        q.pop();
        if(get<0>(tmp) == n and get<1>(tmp) == m) res = min(res, get<2>(tmp));
        if(get<0>(tmp) + a[get<0>(tmp)][get<1>(tmp)] <= n and b[get<0>(tmp) + a[get<0>(tmp)][get<1>(tmp)]][get<1>(tmp)] == 1){
            b[get<0>(tmp) + a[get<0>(tmp)][get<1>(tmp)]][get<1>(tmp)] += b[get<0>(tmp)][get<1>(tmp)];
            q.push({get<0>(tmp) + a[get<0>(tmp)][get<1>(tmp)], get<1>(tmp), b[get<0>(tmp) + a[get<0>(tmp)][get<1>(tmp)]][get<1>(tmp)]});
            // cout << get<0>(tmp) + a[get<0>(tmp)][get<1>(tmp)] << ' ' << get<1>(tmp) << ' ';
            // cout << b[get<0>(tmp) + a[get<0>(tmp)][get<1>(tmp)]][get<1>(tmp)] << endl;
        }
        if(get<1>(tmp) + a[get<0>(tmp)][get<1>(tmp)] <= m and b[get<0>(tmp)][get<1>(tmp) + a[get<0>(tmp)][get<1>(tmp)]] == 1){
            b[get<0>(tmp)][get<1>(tmp) + a[get<0>(tmp)][get<1>(tmp)]] += b[get<0>(tmp)][get<1>(tmp)];
            q.push({get<0>(tmp), get<1>(tmp) + a[get<0>(tmp)][get<1>(tmp)], b[get<0>(tmp)][get<1>(tmp) + a[get<0>(tmp)][get<1>(tmp)]]});
            // cout << "hi " << get<0>(tmp) << ' ' << get<1>(tmp) + a[get<0>(tmp)][get<1>(tmp)] << ' ';
            // cout << b[get<0>(tmp)][get<1>(tmp) + a[get<0>(tmp)][get<1>(tmp)]] << endl;
        }
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                cin >> a[i][j];
                b[i][j] = 1;
            }
        }
        res = 1e9;
        BFS(1, 1);
        if(res != 1e9) cout << res << endl;
        else cout << "-1\n";
    }
}