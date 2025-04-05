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
        vector<int> a(n), b(n, 0);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            if(i) b[i] = b[i - 1] + a[i];
            else b[i] = a[i];
        }
        bool ok = 0;
        for(int i = 0; i < n; ++i){
            if(b[i] == b[n - 1] - b[i - 1]){
                cout << i + 1 << endl;
                ok = 1;
                break;
            }
        }
        if(!ok) cout << -1 << endl;
    }
}