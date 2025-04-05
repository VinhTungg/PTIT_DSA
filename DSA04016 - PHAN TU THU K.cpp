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
        int n, m, k; cin >> n >> m >> k;
        vector<int> a(n), b(m);
        for(auto &x : a) cin >> x;
        for(auto &x : b) cin >> x;
        int x = 0, y = 0, cnt = 0, tmp;
        while(x < n and y < m){
            if(a[x] < b[y]){
                tmp = a[x];
                ++x;
            }
            else{
                tmp = b[y];
                ++y;
            }
            ++cnt;
            if(cnt == k) cout << tmp << endl;
        }
        while(cnt < k){
            if(x < n){
                tmp = a[x];
                ++x;
            }
            else{
                tmp = b[y];
                ++y;
            }
            ++cnt;
            if(cnt == k) cout << tmp << endl;
        }
    }
}