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
        int n, m, k;
        cin >> n >> m >> k;
        vector<ll> a(n), b(m), c(k);
        for(auto &i : a) cin >> i;
        for(auto &i : b) cin >> i;
        for(auto &i : c) cin >> i;
        int x = 0, y = 0, z = 0;
        bool ok = 0;
        while(x < n && y < m && z < k){
            if(a[x] == b[y] && b[y] == c[z]){
                cout << a[x] << " ";
                ok = 1;
                x++; y++; z++;
            }
            else if(a[x] < b[y]) x++;
            else if(b[y] < c[z]) y++;
            else z++;
        }
        if(!ok) cout << -1;
        cout << endl;
    }
}