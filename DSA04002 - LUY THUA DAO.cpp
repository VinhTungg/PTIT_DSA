#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

ll dao(ll n){
    ll res = 0;
    while(n){
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}

ll binPow(ll a, ll b){
    if(b == 0) return 1;
    ll res = binPow(a, b >> 1);
    (res *= res) %= MOD;
    if(b & 1) (res *= a) %= MOD;
    return res;
}

int main(){
    boost;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n;
        k = dao(n);
        cout << binPow(n, k) << endl;
    }
}