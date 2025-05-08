#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

int get_val(ll n, ll k){
    if(n == 0) return 0;
    if(n == 1) return 1;
    int p = 63 - __builtin_clzll(n);
    ll mid = (1LL << p);
    if(k == mid) return n % 2;
    else if(k < mid) return get_val(n / 2, k);
    return get_val(n / 2, k - mid);
}

int main(){
    boost;
    cin >> t;
    while(t--){
        ll n, l, r; cin >> n >> l >> r;
        ll ans = 0;
        for(ll i = l; i <= r; ++i) ans += get_val(n, i);
        cout << ans << endl;
    }
}