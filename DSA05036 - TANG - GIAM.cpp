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
        vector<double> a(n), b(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i] >> b[i];
        }
        int ans = 0;
        vector<int> dp(n + 1, 1);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(a[j] < a[i] and b[j] > b[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
}