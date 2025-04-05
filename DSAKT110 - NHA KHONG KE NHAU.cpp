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
        int n; cin >> n;
        vector<int> dp(n + 1, 0), a(n);
        for(auto &x : a) cin >> x;
        dp[0] = a[0];
        dp[1] = max(a[0], a[1]);
        for(int i = 2; i < n; ++i){
            dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
        }
        cout << dp[n - 1] << endl;
    }
}