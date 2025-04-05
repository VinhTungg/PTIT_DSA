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
        vector<int> v(n);
        for(auto &x : v) cin >> x;
        sort(v.begin(), v.end());
        ll num1 = 0, num2 = 0;
        for(int i = 0; i < v.size(); i += 2) num1 = num1 * 10 + v[i];
        for(int i = 1; i < v.size(); i += 2) num2 = num2 * 10 + v[i];    
        cout << num1 + num2 << endl;
    }
}