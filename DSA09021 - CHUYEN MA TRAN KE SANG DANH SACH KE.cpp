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
        vector<vector<int>> v(n + 1, vector<int>(n + 1));
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j) cin >> v[i][j];
        }
        vector<pair<int, int>> vp;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(v[i][j]){
                    cout << j << ' ';
                }
            }
            cout << endl;
        }
        
    }
}