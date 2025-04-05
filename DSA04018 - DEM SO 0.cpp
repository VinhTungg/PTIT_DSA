#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

int binSearch(vector<int> &a, int x){
    int l = 0, r = a.size() - 1, res = 0, ok = 0;
    while(l <= r){
        int m = (l + r) >> 1;
        if(a[m] == 0){
            l = m + 1;
            res = m;
            ok = 1;
        }else r = m - 1;
    }
    return res + ok;
}

int main(){
    boost;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(auto &x : a) cin >> x;
        cout << binSearch(a, 0) << endl;
    }
}