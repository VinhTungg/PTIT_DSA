#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const ll MOD = 1e15 + 7;

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1;

ll Nhan(ll a, ll b) {
    ll res = 0;
    while(b) {
        if(b & 1) res = (res + a) % MOD;
        a = (a + a) % MOD;
        b >>= 1;
    }
    return res;
}

class Matrix{
   public:
       ll f[4][4]{};
           friend Matrix operator * (Matrix &a, Matrix &b){
           Matrix c;
               for(int i = 0; i < 4; ++i){
                   for(int j = 0; j < 4; ++j){
                   c.f[i][j] = 0;
                   for(int k = 0; k < 4; ++k){
                       c.f[i][j] += Nhan(a.f[i][k], b.f[k][j]);
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
        for (int i = 0; i < 4; ++i) a.f[0][i] = 1;
        for (int i = 1; i < 4; ++i) a.f[1][i] = 1;
        a.f[2][1] = 1; a.f[3][2] = 1;
        if (!n) cout << 0 << endl;
        else if (n == 1) cout << 1 << endl;
        else if (n == 2) cout << 3 << endl;
        else if (n == 3) cout << 6 << endl;
        else {
            Matrix ans = binPow(a, n - 3);
            ll res = 0;
            cerr << ans.f[0][0] << ' ' << ans.f[0][1] << ' ' << ans.f[0][2] << ' ' << ans.f[0][3] << endl;
            res = (ans.f[0][0] * 6 + ans.f[0][1] * 3 + ans.f[0][2] * 2 + ans.f[0][3]) % MOD;
            cout << res << endl;
        }
    }
}