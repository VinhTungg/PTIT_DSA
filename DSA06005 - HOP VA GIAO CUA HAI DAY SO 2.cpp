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
        int n, m;
        cin >> n >> m;
        set<int> a, b, c;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            a.insert(x);
            b.insert(x);
        }
        for(int i = 0; i < m; i++){
            int x;
            cin >> x;
            a.insert(x);
            c.insert(x);
        }
        for(auto &x : a) cout << x << ' ';
        cout << endl;
        for(auto &x : b){
            if(c.find(x) != c.end()) cout << x << ' ';
        }
        cout << endl;
    }
}