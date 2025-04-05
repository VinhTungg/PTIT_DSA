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
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 1), dp(k + 1, 0);
        for(int i = 1; i <= n; ++i) cin >> a[i];
        dp[0] = 1;
        for(int i = 1; i <= k; ++i){
            for(int j = 1; j <= n; ++j){
                if(i >= a[j]) dp[i] = (dp[i] % MOD + dp[i - a[j]] % MOD) % MOD;
            }
        }
        cout << dp[k] << endl;
    }
}