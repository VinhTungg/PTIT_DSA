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
        string a, b;
        cin >> a >> b;
        vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
        for(int i = 0; i <= a.size(); ++i){
            for(int j = 0; j <= b.size(); ++j){
                if(i == 0) dp[i][j] = j;
                else if(j == 0) dp[i][j] = i;
                else if(a[i - 1] == b[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }else dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1});
            }
        }
        cout << dp[a.size()][b.size()] << endl;
    }
}