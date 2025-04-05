#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

int main(){
    boost;
    // cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1), pre(n + 1, 0);
        int tmp = 0;
        for(int i = 1; i <= n; ++i){
            cin >> a[i];
            if(a[i] > 0) tmp += a[i];
            pre[i] = tmp; 
        }
        int l, r;
        while(q--){
            cin >> l >> r;
            if(pre[r] - pre[l - 1]) cout << pre[r] - pre[l - 1] << endl;
            else cout << "0\n";
        }
    }
}