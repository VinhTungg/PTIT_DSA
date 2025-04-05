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
        vector<int> a(n), res;
        for(auto &i : a) cin >> i;
        for(auto &x : a){
            auto it = upper_bound(res.begin(), res.end(), x);
            if(it == res.end()) res.push_back(x);
            else *it = x;
        }
        cout << n - res.size() << endl;
    }
}