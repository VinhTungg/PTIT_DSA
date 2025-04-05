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
        vector<int> a(n + 1), dp1(n + 1), dp2(n + 1);
        for(int i = 1; i <= n; ++i) cin >> a[i];
        for(int i = 1; i <= n; ++i){
            dp1[i] = a[i];
            for(int j = 1; j < i; ++j) if(a[i] > a[j]) dp1[i] = max(dp1[i], dp1[j] + a[i]);
        }
        for(int i = n; i; --i){
            dp2[i] = a[i];
            for(int j = n; j > i; --j) if(a[j] < a[i]) dp2[i] = max(dp2[i], dp2[j] + a[i]);
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i) ans = max(ans, dp1[i] + dp2[i] - a[i]);
        cout << ans << endl;
    }
}