#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
int isprime[1000001]{};

void sieve(){
    isprime[0] = isprime[1] = 0;
    for(int i = 2; i <= 1e6; ++i) isprime[i] = 1;
    for(int i = 2; i <= 1e3; ++i){
        if(isprime[i]){
            for(int j = i * i; j <= 1e6; j += i) isprime[j] = 0;
        }
    }
}

int main(){
    boost;
    cin >> t;
    sieve();
    while(t--){
        int n; cin >> n;
        bool ok = 0;
        for(int i = 2; i <= n / 2; ++i){
            if(isprime[i] and isprime[n - i]){
                ok = 1;
                cout << i << ' ' << n - i << endl;
                break;
            }
        }
        if(!ok) cout << -1 << endl;
    }
}