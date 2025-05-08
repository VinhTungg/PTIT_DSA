#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

int main(){
    boost;
    // cin >> t;
    while(t--){
        int n; cin >> n;
        string s;
        cin >> s;
        int count_X = 0, count_T = 0, count_D = 0;
        for(char &c : s){
            if (c == 'X') count_X++;
            else if (c == 'T') count_T++;
            else count_D++;
        }
        int T_in_X = 0, D_in_X = 0;
        int X_in_T = 0, D_in_T = 0;
        int X_in_D = 0, T_in_D = 0;
        for(int i = 0; i < count_X; ++i){
            if (s[i] == 'T') T_in_X++;
            else if (s[i] == 'D') D_in_X++;
        }
        for(int i = count_X; i < count_X + count_T; ++i){
            if (s[i] == 'X') X_in_T++;
            else if (s[i] == 'D') D_in_T++;
        }
        for(int i = count_X + count_T; i < n; ++i){
            if (s[i] == 'X') X_in_D++;
            else if (s[i] == 'T') T_in_D++;
        }
        int direct_swaps = min(T_in_X, X_in_T) + min(D_in_X, X_in_D) + min(D_in_T, T_in_D);
        int cycle_swaps = 2 * ((T_in_X - min(T_in_X, X_in_T)) + (D_in_X - min(D_in_X, X_in_D)));
        int ans = direct_swaps + cycle_swaps;
        cout << ans << endl;
    }
}