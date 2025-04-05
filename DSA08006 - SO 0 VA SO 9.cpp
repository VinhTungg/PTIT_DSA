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
        queue<ll> q;
        q.push(9);
        while(1){
            ll x = q.front();
            q.pop();
            if(x % n == 0){
                cout << x << endl;
                break;
            }
            q.push(x * 10);
            q.push(x * 10 + 9);
        }
    }
}