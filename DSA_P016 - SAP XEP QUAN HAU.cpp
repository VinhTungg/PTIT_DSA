#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, ans;
vector<vector<int>> v;
vector<bool> cheo1, cheo2, cot;

void Try(int i, int sum = 0){
    for(int j = 1; j <= 8; ++j){
        if(!cot[j] and !cheo1[i + j - 1] and !cheo2[i - j + 8]){
            cot[j] = true;
            cheo1[i + j - 1] = true;
            cheo2[i - j + 8] = true;
            if(i == 8){
                ans = max(ans, sum + v[i][j]);
            }
            else if(i < 8) Try(i + 1, sum + v[i][j]);
            cot[j] = false;
            cheo1[i + j - 1] = false;
            cheo2[i - j + 8] = false;
        }
    }
}

int main(){
    boost;
    cin >> t;
    for(int _ = 1; _ <= t; ++_){
        v.resize(9);
        for(int i = 1; i <= 8; ++i) v[i].resize(9);
        for(int i = 1; i <= 8; ++i) {
            for(int j = 1; j <= 8; ++j) cin >> v[i][j];
        }
        cot.assign(20, false);
        cheo1.assign(20, false); cheo2.assign(20, false);
        ans = INT_MIN;
        cout << "Test " << _ << ": ";
        Try(1);
        cout << ans << endl;
    }
}