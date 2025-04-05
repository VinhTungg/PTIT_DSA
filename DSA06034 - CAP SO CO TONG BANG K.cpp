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
        int n, k; cin >> n >> k;
        unordered_map<ll, int> mp;
        for(int i = 0; i < n; ++i){
            ll x; cin >> x;
            mp[x]++;
        }
        ll res = 0;
        for(auto i : mp){
            if(mp.find(k - i.first) != mp.end() and i.second and mp[k - i.first]){
                if(i.first != k - i.first) res += (1ll * i.second * mp[k - i.first]);
                else res += 1ll * i.second * (i.second - 1) / 2;
                i.second = 0;
                mp[k - i.first] = 0;
            }
        }
        cout << res << endl;
    }
}