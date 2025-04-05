#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n, m, res = 0;
vector<vector<bool>> v;

void Try(int i, int sum = 0){
    res = max(res, sum);
    for(int j = 0; j < n; ++j){
        if(v[i][j]){
            v[i][j] = v[j][i] = 0;
            Try(j, sum + 1);
            v[i][j] = v[j][i] = 1;
        }
    }
}

int main(){
    cin >> t;
    int a, b;
    while(t--){
        cin >> n >> m;
        v.resize(n + 1, vector<bool> (n + 1));
        for(int i = 0; i < m; ++i){
            cin >> a >> b;
            v[a][b] = v[b][a] = 1;
        }
        for(int i = 1; i < n; ++i) Try(i);
        cout << res << endl;
        v.clear();
    }
}