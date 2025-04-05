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
        ll n;
        cin >> n;
        queue<ll> q;
        q.push(1);
        int cnt = 0;
        while(1){
            ll x = q.front();
            q.pop();
            ++cnt;
            if(x * 10 <= n) q.push(x * 10);
            else break;
            if(x * 10 + 1 <= n) q.push(x * 10 + 1);
            else break;
        }
        cout << cnt + q.size() << endl;
    }
}