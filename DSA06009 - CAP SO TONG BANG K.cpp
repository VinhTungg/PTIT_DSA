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
        unordered_map<int, int> mp;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            mp[x]++;
        }
        ll ans = 0;
        for(auto &x : mp){
            if(mp.find(k - x.first) != mp.end()){
                if(x.first != k - x.first) ans += (1ll * x.second * mp[k - x.first]);
                else ans += (1ll * x.second * (x.second - 1) / 2);
                x.second = 0;
            }
        }
        cout << ans << endl;
    }
}