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
        vector<int> v(n);
        for(auto &x : v) cin >> x;
        for(int i = 0; i < n - k + 1; i++){
            cout << *max_element(v.begin() + i, v.begin() + i + k) << " ";
        }
        cout << endl;
    }
}