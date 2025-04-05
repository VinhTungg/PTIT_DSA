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
        ll max_a = LLONG_MIN, min_b = LLONG_MAX;
        for(auto &x : a){
            cin >> x;
            max_a = max(max_a, (ll)x);
        }
        for(auto &x : b){
            cin >> x;
            min_b = min(min_b, (ll)x);
        }
        cout << max_a * min_b << endl;
    }
}