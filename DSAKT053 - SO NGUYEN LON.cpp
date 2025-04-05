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
        string n, m;
        cin >> n >> m;
        vector<vector<int>> dp(n.size() + 1, vector<int>(m.size() + 1, 0));
        for(int i = 0; i < n.size(); ++i){
            for(int j = 0; j < m.size(); ++j){
                if(n[i] == m[j]){
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                }else{
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        cout << dp[n.size()][m.size()] << endl;
    }
}