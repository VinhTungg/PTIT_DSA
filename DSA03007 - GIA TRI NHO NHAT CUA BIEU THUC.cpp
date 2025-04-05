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
        vector<int> a(n), b(n);
        for(auto &x : a) cin >> x;
        for(auto &x : b) cin >> x;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<int>());
        ll res = 0;
        for(int i = 0; i < n; ++i) res += 1ll * a[i] * b[i];
        cout << res << endl;  
    }
}