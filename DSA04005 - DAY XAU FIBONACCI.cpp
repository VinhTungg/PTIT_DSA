#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
ll F[93] = {};

void fibo(){
    F[0] = 0;
    F[1] = 1;
    for(int i = 2; i < 93; i++){
        F[i] = F[i - 1] + F[i - 2];
    }
}
string findAB(ll n, ll i){
    if(n == 1) return "A";
    else if(n == 2) return "B";
    if(i <= F[n - 2]) return findAB(n - 2, i);
    else return findAB(n - 1, i - F[n - 2]);
}

int main(){
    boost;
    cin >> t;
    fibo();
    while(t--){
        ll n, i;
        cin >> n >> i;
        cout << findAB(n, i) << endl;
    }
}