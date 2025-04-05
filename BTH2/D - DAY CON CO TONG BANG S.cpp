#include <bits/stdc++.h>
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define endl '\n'
#define MOD 1000000007

using namespace std;
int t = 1;

int main(){
    boost;
    cin >> t;
    while(t--){
        int n, s; cin >> n >> s;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i++) cin >> a[i];
        vector<vector<int>> dp(n + 1, vector<int>(s + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= s; j++){
                dp[i][j] = dp[i - 1][j];
                if(j >= a[i]) dp[i][j] = (dp[i][j] || dp[i - 1][j - a[i]]);
            }
        }
        cout << (dp[n][s] ? "YES" : "NO") << endl;
    }
    
}