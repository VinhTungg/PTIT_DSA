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
        ll dp[n + 1]{};
        dp[0] = 1;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= min(i, 3); ++j){
                dp[i] += dp[i - j];
            }
        }   
        cout << dp[n] << endl;
    }
}