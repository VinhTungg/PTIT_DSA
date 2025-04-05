#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

int main(){
    boost;
    //cin >> t;
    while(t--){
        int n; cin >> n;
        int mark[100001]{}, a[n], res = 0;
        for(auto &x : a){
            cin >> x;
            mark[x] = mark[x - 1] + 1;
            res = max(res, mark[x]);
        }
        cout << n - res;
    }
}