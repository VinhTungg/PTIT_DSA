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
        int n, m; cin >> n >> m;
        vector<int> a(n), b(m);
        int num[5]{};
        for(int &x : a) cin >> x;
        for(int &x : b){
            cin >> x;
            if(x < 5) num[x]++;
        }
        sort(b.begin(), b.end());
        ll ans = 0;
        for(int i = 0; i < n; ++i){
            int pos = n - (upper_bound(b.begin(), b.end(), a[i]) - b.begin());
            if(!a[i]) continue;
            if(a[i] == 1) ans += num[0];
            if(a[i] == 2) ans -= (num[3] + num[4]);
            if(a[i] == 3) ans += num[2];
            if(a[i] > 1){
                ans += pos;
                ans += (num[0] + num[1]);
            }
        }
        cout << ans << endl;
    }
}