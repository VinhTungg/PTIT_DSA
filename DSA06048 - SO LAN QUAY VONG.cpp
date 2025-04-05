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
        vector<ll> a(n), b;
        for(ll &i : a) cin >> i;
        b = a;
        sort(b.begin(), b.end());
        int res = 0;
        if(b != a) {
            for(int i = 0; i < n; ++i){
                if(a[i] != b[n - 1]) res++;
                else{
                    while(i < n && a[i] == b[n - 1]){
                        i++;
                        ++res;
                    }
                    break;
                }
            }
        }
        cout << res << endl;
    }
}