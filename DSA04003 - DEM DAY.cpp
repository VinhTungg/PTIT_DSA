#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
const int MAX = 123456789;

ll binPow(ll a, ll b){
    if(b == 0) return 1;
    ll res = binPow(a, b >> 1);
    (res *= res) %= MAX;
    if(b & 1) (res *= a) %= MAX;
    return res;
}

int main(){
    boost;
    cin >> t;
    while(t--){
        ll n; cin >> n;
        cout << binPow(2, n - 1) << endl;  
    }
}