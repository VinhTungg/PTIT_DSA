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
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for(auto &x : a) cin >> x;
        sort(a.begin(), a.end(), greater<int>());
        for(int i = 0; i < k; ++i) cout << a[i] << ' ';
        cout << endl;
    }
}