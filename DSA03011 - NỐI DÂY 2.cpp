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
        int n; cin >> n;
        ll ans = 0;
        priority_queue<ll, vector<ll>, greater<ll>> q;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            q.push(x);
        }
        ll tmp;
        while(q.size() > 1){
            ll a = q.top();
            q.pop();
            ll b = q.top();
            q.pop();
            tmp = (a + b) % MOD;
            ans = (ans + tmp) % MOD;
            q.push(tmp);
        }
        cout << ans << endl;
    }
}