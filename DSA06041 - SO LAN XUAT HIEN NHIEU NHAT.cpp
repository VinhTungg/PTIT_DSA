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
        vector<int> a(n), b(1000001, 0);
        for(int &i : a){
            cin >> i;
            b[i]++;
        }
        bool ok = 0;
        for(int i = 0; i < n; ++i){
            if(b[a[i]] > n / 2){
                cout << a[i] << endl;
                ok = 1;
                break;
            }
        }
        if(!ok) cout << "NO" << endl;
    }
}