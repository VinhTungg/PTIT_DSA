#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

int binary_search(vector<int> &a, int &x){
    int l = 0, r = a.size() - 1;
    while(l <= r){
        int m = (l + r) >> 1;
        if(a[m] == x){
            return m + 1;
        }else if(a[m] < x){
            l = m + 1;
        }else r = m - 1;
    }
    return -1;
}

int main(){
    boost;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(auto &x : a) cin >> x;
        int res = binary_search(a, k);
        if(res == -1) cout << "NO" << endl;
        else cout << res << endl;
    }
}