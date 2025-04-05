#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n;
vector<vector<ll>> cost, dp;

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n;
        cost.assign(n + 1, vector<ll>(n + 1, 0));
        dp.assign(1 << n, vector<ll>(n + 1, INT_MAX));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j) cin >> cost[i][j];
        }
        for(int i = 0; i < n; ++i) dp[1 << i][i] = 0;
        for(int mask = 0; mask < (1 << n); ++mask){
            for(int i = 0; i < n; ++i){
                if(mask & (1 << i)){
                    for(int j = 0; j < n; ++j){
                        if(!(mask & (1 << j))){
                            int new_mask = mask | (1 << j);
                            dp[new_mask][j] = min(dp[new_mask][j], dp[mask][i] + cost[i][j]);
                        }
                    }
                }
            }
        }
        ll ans = INT_MAX;
        for(int i = 0; i < n; ++i) ans = min(ans, dp[(1 << n) - 1][i]);
        cout << ans << endl;
    }
}