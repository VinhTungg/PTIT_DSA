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
        int x, y, z;
        cin >> x >> y >> z;
        vector<int> dp(n + 1, 0);
        for(int i = 1; i <= n; ++i){
            dp[i] = dp[i - 1] + x;
            if(i & 1) dp[i] = min(dp[i], dp[(i + 1) >> 1] + y + z);
            else dp[i] = min(dp[i], dp[i >> 1] + z);
        }
        cout << dp[n] << endl;
    }
}