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

int main() {
    boost;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        ll ans = 0;
        ll sum = 0;
        for (int i = 0; i < s.length(); ++i) {
            sum = (sum * 10 + (i + 1) * (s[i] - '0'));
            ans = (ans + sum);
        }
        cout << ans << "\n";
    }
    // time;
}