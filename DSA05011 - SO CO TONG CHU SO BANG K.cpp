#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n, k;
vector<vector<int>> dp(105, vector<int>(50005, 0));

void init(){
    dp[0][0] = 1;
    for(int i = 1; i <= 100; ++i){
        for(int j = 0; j <= 50000; ++j){
            for(int k = 0; k <= 9; ++k){
                if(j >= k) dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD;
            }
        }
    }
}

int main(){
    boost;
    cin >> t;
    init();
    while(t--){
        cin >> n >> k;
        int ans = (dp[n][k] - dp[n - 1][k] + MOD) % MOD;
        cout << ans << endl;
    }
}