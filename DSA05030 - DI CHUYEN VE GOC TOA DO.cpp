#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
ll dp[26][26];

void init(){
    for(int i = 1; i <= 25; ++i) dp[0][i] = dp[i][0] = 1;
    for(int i = 1; i <= 25; ++i){
        for(int j = 1; j <= 25; ++j){
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
}

int main(){
    boost;
    cin >> t;
    init();
    while(t--){
        int n, m;
        cin >> n >> m;
        cout << dp[n][m] << endl;
    }
}