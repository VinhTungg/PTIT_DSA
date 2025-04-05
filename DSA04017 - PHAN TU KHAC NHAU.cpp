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
        vector<ll> a(n), b(n);
        for(auto &x : a) cin >> x;
        for(int i = 0; i < n - 1; ++i) cin >> b[i];
        for(int i = 0; i < n - 1; ++i){
            if(a[i] != b[i]){
                cout << i + 1 << endl;
                break;
            }
        }
    }
}