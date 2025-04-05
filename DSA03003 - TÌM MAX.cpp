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
        int n; 
        cin >> n;
        vector<ll> v(n);
        for(auto &x : v) cin >> x;
        sort(v.begin(), v.end());
        ll sum = 0, cnt = 0;
        for(auto &x : v){
            sum = (sum + 1ll * x * cnt++) % MOD; 
        }   
        cout << sum << endl; 
    }
}