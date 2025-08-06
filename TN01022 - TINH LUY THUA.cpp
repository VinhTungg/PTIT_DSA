#include <bits/stdc++.h>
#define ll long long
#define boost cin.tie(0) -> sync_with_stdio(0)
#define time cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1;
ll a, b;

ll binPow(ll a, ll b){
    if(b == 0) return 1;
    ll res = binPow(a, b >> 1);
    (res *= res) %= MOD;
    if(b & 1) (res *= a) %= MOD;
    return res;
}

int main() {
    boost;
    //cin >> t;
    while (cin >> a >> b) {
        if (!a and !b) break;
        cout << binPow(a, b) << endl;
    }
    time;
}