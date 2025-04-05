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
        int tang = 0, giam = 0, res = 0, ok = 0;
        vector<int> a(n);
        for(auto &i : a) cin >> i;
        for(int i = 0; i < n - 1; ++i){
            if(a[i] < a[i + 1]){
                if(giam){
                    res = max(res, tang + giam + 1);
                    tang = 1;
                    giam = 0;
                }else{
                    ++tang;
                }
                ok = 0;
            }
            else if(a[i] > a[i + 1]){
                if(ok) ++giam;
                else {
                    giam = 1;
                    ok = 1;
                }
            }
        }
        res = max(res, tang + giam + 1);
        cout << res << endl;
    }
}