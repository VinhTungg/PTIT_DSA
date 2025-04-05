#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n;
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
ll res;

void Try(int i, ll ans, ll uoc){
    if(uoc > n || ans > res) return;
    else if(uoc == n) res = min(res, ans);
    else{
        for(int j = 1; ; ++j){
            if(ans * primes[i] > res) break;
            ans *= primes[i];
            Try(i + 1, ans, uoc * (j + 1));
        }
    }
}

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        res = 1e18;
        Try(0, 1, 1);
        cout << res << endl;
    }
}