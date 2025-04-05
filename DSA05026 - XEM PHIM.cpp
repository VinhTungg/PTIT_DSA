#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

int main(){
    boost;
    // cin >> t;
    while(t--){
        int c, n;
        cin >> c >> n;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        ll dp[n + 1][c + 1]{};
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= c; ++j){
                if(j >= a[i]){
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i]] + a[i]);
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        cout << dp[n][c] << endl;
    }
}