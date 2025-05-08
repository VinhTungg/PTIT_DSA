#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
const int A_max = 100, B_max = 10000, INF = 1000;
int dp[A_max + 1][B_max + 1];

void init(){
    for(int i = 0; i <= A_max; ++i){
        for(int j = 0; j <= B_max; ++j) dp[i][j] = INF;
    }
    dp[0][0] = 0;
    for(int digits = 0; digits <= 9; ++digits){
        int square = digits * digits;
        for(int i = digits; i <= A_max; ++i){
            for(int j = square; j <= B_max; ++j){
                dp[i][j] = min(dp[i][j], dp[i - digits][j - square] + 1);
            }
        }
    }
}

int main(){
    boost;
    init();
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        if(dp[a][b] > 100) cout << "-1\n";
        else{
            string s = "";
            while(a){
                for(int digits = 1; digits <= 9; ++digits){
                    int square = digits * digits;
                    if(a >= digits and b >= square and dp[a][b] == dp[a - digits][b - square] + 1){
                        s += to_string(digits);
                        a -= digits;
                        b -= square;
                        break;
                    }
                }
            }
            cout << s << endl;
        }
    }
}