#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
vector<int> dp(10001, 1e9);

void init(){
    dp[0] = 0;
    for(int i = 1; i <= 1e4; ++i){
        for(int j = 1; j * j <= i; ++j){
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
}

int main(){
    boost;
    cin >> t;
    init();
    while(t--){
        int n; cin >> n;
        cout << dp[n] << endl;
    }
}