#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
ll C[110][110];

void init(){
    for(int i = 0; i <= 109; ++i){
        for(int j = 0; j <= i; ++j){
            if(j == 0 or i == j) C[i][j] = 1;
            else{
                C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
            }
        }
    }
}

int main(){
    boost;
    cin >> t;
    init();
    while(t--){
        int n; cin >> n;
        cout << C[n + 9][n] << endl;
    }
}