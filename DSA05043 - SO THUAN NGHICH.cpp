#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
int dp[1005][1005];

int main(){
    boost;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        memset(dp, 0, sizeof(dp));
        int n = s.length();
        s = "0" + s;
        int ans = 1;
        for(int i = 1; i <= n; ++i) dp[i][i] = 1;
        for(int len = 2; len <= n; ++len){
            for(int i = 1; i <= n; ++i){
                int j = i + len - 1;
                if(len == 2) dp[i][j] = (s[i] == s[j]);
                else dp[i][j] = (s[i] == s[j] and dp[i + 1][j - 1]);
                if(dp[i][j]) ans = max(ans, len);
            }
        }
        cout << ans << endl;
    }
}

/* Xâu con liên tiếp đối xứng dài nhất */