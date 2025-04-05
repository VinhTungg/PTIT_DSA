#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define endl '\n'
#define MOD 1000000007

int main(){
    boost;
    int t = 1;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n + 1), dp(n + 1, -1e9);
        for(int i = 1; i <= n; i++) cin >> a[i];
        dp[1] = a[1];
        int res = dp[1];
        for(int i = 2; i <= n; i++){
            dp[i] = max(a[i], dp[i - 1] + a[i]);
            res = max(res, dp[i]);
        }
        cout << res << endl;
    }
}