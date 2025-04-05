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
        int x, y, z;
        cin >> x >> y >> z;
        string a, b, c;
        cin >> a >> b >> c;
        int dp[x + 1][y + 1][z + 1]{};
        for(int i = 1; i <= x; ++i){
            for(int j = 1; j <= y; ++j){
                for(int k = 1; k <= z; ++k){
                    if(a[i - 1] == b[j - 1] and b[j - 1] == c[k - 1]) dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                    else dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                }
            }
        }
        cout << dp[x][y][z] << endl;
    }
}