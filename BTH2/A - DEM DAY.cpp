#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define endl '\n'
#define MOD 123456789

ll calc(ll n){
    if(n == 1) return n;
    ll x = calc(n >> 1) % MOD;
    if(n & 1) return ((x * x) % MOD << 2) % MOD;
    return (((x * x) % MOD << 1) % MOD) % MOD;
}

int main(){
    int t = 1;
    cin >> t;
    while(t--){
        ll n; cin >> n;
        cout << calc(n) << endl;
    }
}