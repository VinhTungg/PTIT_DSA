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
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for(auto &i : a) cin >> i;
        vector<int> dp(n, -1e9);
        dp[0] = 0;
        for(auto &i : a){
            int remaider = i % k;
            vector<int> new_dp = dp;
            for(int j = 0; j < k; ++j){
                int new_remain = (remaider + j) % k;
                new_dp[new_remain] = max(new_dp[new_remain], dp[j] + 1);
            }
            dp = new_dp;
        }
        cout << dp[0] << endl;
    }
}