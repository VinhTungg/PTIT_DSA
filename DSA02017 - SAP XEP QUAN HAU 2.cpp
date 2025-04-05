#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n, ans;
int X[10][10];
bool Cot[16], Xuoi[16], Nguoc[16];

void Try(int i, int sum = 0){
    for(int j = 1; j <= 8; ++j){
        if(!Cot[j] and !Xuoi[8 + i - j] and !Nguoc[i + j - 1]){
            Cot[j] = 1, Xuoi[8 + i - j] = 1, Nguoc[i + j - 1] = 1;
            if(i == 8) ans = max(ans, sum + X[i][j]);
            else if(i < 8) Try(i + 1, sum + X[i][j]);
            Cot[j] = 0, Xuoi[8 + i - j] = 0, Nguoc[i + j - 1] = 0;
        }
    }
}

int main(){
    cin >> t;
    while(t--){
        // cin >> n;
        for(int i = 1; i < 9; ++i) for(int j = 1; j < 9; ++j) cin >> X[i][j];
        ans = INT_MIN;
        memset(Cot, 0, sizeof(Cot));
        memset(Xuoi, 0, sizeof(Xuoi));
        memset(Nguoc, 0, sizeof(Nguoc));
        Try(1);
        cout << ans << endl;
    }
}