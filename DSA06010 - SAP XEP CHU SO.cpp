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
        vector<string> v(n);
        int f[10]{};
        for(auto &x : v){
            cin >> x;
            for(auto &c : x) f[c - '0']++;
        }
        for(int i = 0; i < 10; ++i){
            if(f[i]) cout << i << ' ';
        }
        cout << endl;
    }
}