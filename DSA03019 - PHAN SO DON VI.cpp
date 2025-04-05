#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

void solve(ll n, ll m){
    int tmp;
    while(true){
        if(m % n == 0){
            cout << "1/" << m / n << endl;
            break;
        }
        else{
            tmp = m / n + 1;
            cout << "1/" << tmp << " + ";
            n = n * tmp - m;
            m = m * tmp;
            if(n == 1){
                cout << "1/" << m << endl;
                break;
            }
        }
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        solve(n, m);
    }
}