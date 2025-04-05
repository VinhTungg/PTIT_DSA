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
        int m, n;
        cin >> m >> n;
        vector<ll> a(m), b(n), ans(m + n - 1);
        for(auto &x : a) cin >> x;
        for(auto &x : b) cin >> x;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j) ans[i + j] += (a[i] * b[j]);
        }
        for(auto &x : ans) cout << x << ' ';
        cout << endl;
    }
}