#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

int main(){
    boost;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n + 1, vector<int> (m + 1)), dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j) cin >> a[i][j];
        }
        for(int i = 1; i <= n; ++i) dp[i][1] = dp[i - 1][1] + a[i][1];
        for(int i = 1; i <= m; ++i) dp[1][i] = dp[1][i - 1] + a[1][i];
        for(int i = 2; i <= n; ++i){
            for(int j = 2; j <= m; ++j){
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + a[i][j];
            }
        }
        cout << dp[n][m] << endl;
    }
}