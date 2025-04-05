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
        vector<int> a(n), b(m), c(k);
        for(auto &x : a) cin >> x;
        for(auto &x : b) cin >> x;
        for(auto &x : c) cin >> x;
        vector<int> res;
        int x = 0, y = 0, z = 0;
        while(x < n && y < m && z < k){
            if(a[x] == b[y] && b[y] == c[z]){
                res.push_back(a[x]);
                ++x, ++y, ++z;
            }
            else if(a[x] < b[y]) ++x;
            else if(b[y] < c[z]) ++y;
            else ++z;
        }
        if(res.empty()) cout << "NO";
        else for(auto x : res) cout << x << " ";
        cout << endl;
    }
}