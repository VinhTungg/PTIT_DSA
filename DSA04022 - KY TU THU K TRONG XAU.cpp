#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
char alpha[30];

void create(){
    for(int i = 0; i <= 26; ++i){
        alpha[i + 1] = 'A' + i;
    }
}

ll binPow(ll a, ll b){
    if(b == 0) return 1;
    ll res = binPow(a, b >> 1);
    res *= res;
    if(b & 1) res *= a;
    return res;
}

char findNumK(ll a, ll b){
    ll res = binPow(2, a - 1);
    if(b == res) return alpha[a];
    if(b < res) return findNumK(a - 1, b);
    return findNumK(a - 1, b - res);
}

int main(){
    boost;
    cin >> t;
    create();
    while(t--){
        ll n, k;
        cin >> n >> k;
        cout << findNumK(n, k) << endl;
    }
}