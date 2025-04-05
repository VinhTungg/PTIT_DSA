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
        vector<int> a(n), b(n, 1);
        for(auto &x : a) cin >> x;
        int max_arr = *max_element(a.begin(), a.end());
        ll ans = LLONG_MAX;
        for(int i = 1; i <= max_arr; ++i){
            bool ok = true;
            ll sumB = 0;
            for(int j = 0; j < n; ++j){
                int L = a[j] / (i + 1) + 1;
                int R = a[j] / i;
                if(L > R){
                    ok = false;
                    break;
                }
                sumB += 1ll * L;
            }
            if(ok) ans = min(ans, sumB);
        }
        cout << ans << endl;
    }
}