#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

class Matrix{
    public:
        ll f[2][2];
        friend Matrix operator * (Matrix &a, Matrix &b){
            Matrix c;
            for(int i = 0; i < 2; ++i){
                for(int j = 0; j < 2; ++j){
                    c.f[i][j] = 0;
                    for(int k = 0; k < 2; ++k){
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
        ll n;
        cin >> n;
        Matrix a;
        a.f[0][0] = a.f[0][1] = a.f[1][0] = 1;
        a.f[1][1] = 0;
        Matrix ans = binPow(a, n - 1);
        cout << ans.f[0][0] << endl;
    }
}