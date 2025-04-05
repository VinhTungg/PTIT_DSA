#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
ll C[1001], GT[1001][1001];

void init(){
    C[0] = 1;
    for(int i = 1; i <= 1000; ++i){
        C[i] = C[i - 1] * i;
        C[i] %= MOD;
    }
}

ll binPow(ll a, ll b){
    if(b == 0) return 1;
    ll res = binPow(a, b >> 1);
    (res *= res) %= MOD;
    if(b & 1) (res *= a) %= MOD;
    return res;
}

ll solve(int n, int k){
    if(k > n) return 0;
    return (C[n] * binPow(C[n - k], MOD - 2)) % MOD;
}

int main(){
    boost;
    cin >> t;
    init();
    while(t--){
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
}