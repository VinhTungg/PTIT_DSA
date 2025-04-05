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
        int n, v;
        cin >> n >> v;
        vector<int> a(n + 1), c(n + 1);
        vector<vector<int>> dp(n + 1, vector<int> (v + 1, 0));
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> c[i];
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= v; ++j){
                if(j < a[i]) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i]] + c[i]);
            }
        }
        cout << dp[n][v] << endl;
    }
}