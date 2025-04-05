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
        string s, r; cin >> s;
        int n = s.length();
        r = s;
        reverse(s.begin(), s.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(s[i - 1] == r[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        cout << n - dp[n][n] << endl;
    }
}

/*
    Tìm xâu con đối xứng dài nhất bằng cách đảo ngược xâu
    Bài toán đưa về tìm xâu con chung dài nhất
*/