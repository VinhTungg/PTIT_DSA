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
        for(int i = 1; i <= n; ++i) cin >> a[i];
        for(int i = 1; i <= n; ++i) cin >> c[i];
        ll dp[v + 1]{};
        for(int i = 1; i <= n; ++i){
            for(int j = v; j >= a[i]; --j){
                dp[j] = max(dp[j], dp[j - a[i]] + c[i]);
            }
        }
        cout << dp[v] << endl;
    }
}