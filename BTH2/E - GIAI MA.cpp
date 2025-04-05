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
        string s; cin >> s;
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            if(s[i - 1] != '0') dp[i] = dp[i - 1];
            if(i > 1 and s[i - 2] != '0' and stoi(s.substr(i - 2, 2)) <= 26) dp[i] = dp[i] + dp[i - 2];
        }
        cout << dp[n] << endl;
    }
}