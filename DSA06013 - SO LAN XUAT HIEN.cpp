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
        int n, x; cin >> n >> x;
        vector<int> a(1000001);
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            a[x]++;
        }
        cout << (a[x] ? a[x] : -1) << endl;
    }
}