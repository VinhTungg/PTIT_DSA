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
        int k; cin >> k;
        string s;
        cin >> s;
        priority_queue<ll> pq;
        ll fre[26]{};
        for(auto &x : s){
            fre[x - 'A']++;
        }
        for(int i = 0; i < 26; ++i) if(fre[i]) pq.push(fre[i]);
        while(k--){
            ll tmp = pq.top();
            pq.pop();
            if(tmp > 1) pq.push(tmp - 1);
        }
        ll ans = 0;
        while(!pq.empty()){
            ans += pq.top() * pq.top();
            pq.pop();
        }
        cout << ans << endl;
    }
}