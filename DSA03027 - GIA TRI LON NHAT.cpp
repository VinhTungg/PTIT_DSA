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
        vector<int> a(n);
        ll ans = 0;
        for(auto &x : a){
            cin >> x;
            if(x > 0) ans += 1ll * 2 * x;
        }
        cout << ans;
    }
}