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
        string s;
        cin >> s;
        int n = s.length();
        string r = s;
        reverse(r.begin(), r.end());
        int dp[n + 1][n + 1]{};
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(s[i] == r[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
                else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        cout << n - dp[n][n] << endl;
    }
}