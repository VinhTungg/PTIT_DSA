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
        ll n, k, res = 0; cin >> n >> k;
        vector<ll> a(n);
        for(ll &i : a) cin >> i;
        sort(a.begin(), a.end());
        for(int i = 0; i < n; ++i){
            res += lower_bound(a.begin() + i + 1, a.end(), a[i] + k) - (a.begin() + i + 1);
        }
        cout << res << endl;
    }
}