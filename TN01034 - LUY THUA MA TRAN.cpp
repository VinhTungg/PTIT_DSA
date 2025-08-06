#include <bits/stdc++.h>
#define ll long long
#define boost cin.tie(0) -> sync_with_stdio(0)
#define time cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, n, m;

class Matrix{
   public:
       ll f[12][12];
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
    while(t--) {
        cin >> n >> m;
        Matrix a;
        for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) cin >> a.f[i][j];
        Matrix ans = binPow(a, m);
        ll res = 0;
        for(int i = 0; i < n; ++i) res = (res + ans.f[i][n - 1]) % MOD;
        cout << res << endl;
    }
}