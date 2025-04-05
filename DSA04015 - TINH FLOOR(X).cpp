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
        int n, x; cin >> n >> x;
        vector<ll> a(n + 1);
        for(int i = 1; i <= n; ++i) cin >> a[i];
        int i = 1;
        bool ok = false;
        while(i > 0 and i <= n){
            if(a[i] > x){
                --i;
                if(i != 0) ok = true;
                break;
            }else ++i;
        }
        if(i == n + 1) --i;
        if(ok) cout << i << endl;
        else cout << -1 << endl;
    }
}