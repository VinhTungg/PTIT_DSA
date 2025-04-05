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
    while (t--) {
        int n;
        cin >> n;
        ll ans = 0;
        priority_queue<ll, vector<ll>, greater<ll>> q;
        for (int i = 0; i < n; ++i) {
            ll x;
            cin >> x;
            q.push(x);
        }
        while (q.size() > 1) {
            ll tmp = q.top();
            q.pop();
            tmp += q.top();
            q.pop();
            ans += tmp;
            q.push(tmp);
        }
        cout << ans << endl;
    }
}