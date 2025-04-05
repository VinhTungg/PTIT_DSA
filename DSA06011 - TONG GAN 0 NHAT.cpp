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
        vector<int> a(n);
        for(auto &x : a) cin >> x;
        ll ans = 1e6;
        for(int i = 0; i < n - 1; ++i){
            for(int j = i + 1; j < n; ++j){
                if(abs(ans) > abs(a[i] + a[j])) ans = a[i] + a[j];
            }
        }
        cout << ans << endl;
    }
}