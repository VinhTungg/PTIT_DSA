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
        vector<int> a(n);
        for(int &i : a) cin >> i;
        sort(a.begin(), a.end());
        int res = INT_MAX;
        for(int i = 1; i < n; ++i){
            res = min(res, a[i] - a[i - 1]);
        }
        cout << res << endl;
    }
}