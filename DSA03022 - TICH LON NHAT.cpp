#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

int main(){
    boost;
    //cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> a(n);
        for(auto &x : a) cin >> x;
        sort(a.begin(), a.end());
        cout << max({a[0] * a[1], a[n - 1] * a[n - 2], a[0] * a[1] * a[n - 1], a[n - 1] * a[n - 2] * a[n - 3]});
    }
}