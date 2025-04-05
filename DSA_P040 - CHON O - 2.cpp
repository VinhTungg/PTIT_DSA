#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n;
vector<vector<ll>> a, dp;
int config[] = {1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0};

ll Get_Val(int i, int j){
    ll tmp = 0;
    for(int z = 0; z < 4; ++z){
        if(j & (1 << z)) tmp += a[z][i];
    }
    return tmp;
}


int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n;
        a.assign(4, vector<ll>(n + 1, 0));
        dp.assign(n + 1, vector<ll>(1 << 4, -1e9));
        ll res = LLONG_MIN;
        for(int i = 0; i < 4; ++i){
            for(int j = 1; j <= n; ++j){
                cin >> a[i][j];
                res = max(res, a[i][j]);
            }
        }
        if(res < 0){
            cout << res << endl;
            continue;
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j < 16; ++j){
                if(config[j]){
                    ll Val = Get_Val(i, j);
                    if(i == 1) dp[i][j] = Val;
                    else{
                        dp[i][j] = -1e9;
                        for(int k = 0; k < 16; ++k){
                            if(config[k] and !(j & k)){
                                dp[i][j] = max(dp[i][j], dp[i - 1][k] + Val);
                            }
                        }
                    }
                }
            }
        }
        cout << *max_element(dp[n].begin(), dp[n].begin() + 16) << endl;
    }
}