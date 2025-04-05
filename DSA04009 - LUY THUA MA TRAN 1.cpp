#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n, k;

class Matrix{
   public:
       ll f[11][11];
           friend Matrix operator * (Matrix &a, Matrix &b){
           Matrix c;
               for(int i = 0; i < n; ++i){
                   for(int j = 0; j < n; ++j){
                   c.f[i][j] = 0;
                   for(int k = 0; k < n; ++k){
                       c.f[i][j] += (a.f[i][k] * b.f[k][j]) % MOD;
                       c.f[i][j] %= MOD;
                   }
               }
           }
           return c;
        }
};

Matrix binPow(Matrix a, ll b){
    if(b == 1) return a;
    Matrix res = binPow(a, b >> 1);
    res = res * res;
    if(b & 1) res = res * a;
    return res;
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n >> k;
        Matrix a;
        for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) cin >> a.f[i][j];
        Matrix ans = binPow(a, k);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j) cout << ans.f[i][j] << ' ';
            cout << endl;
        }
    }
}