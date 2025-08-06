#include <bits/stdc++.h>
#define ll long long
#define boost cin.tie(0) -> sync_with_stdio(0)
#define time cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, n, k;

int main() {
    boost;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int dp[n + 1]{1};
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                if (i - j >= 0) (dp[i] += dp[i - j]) %= MOD;
            }
        }
        cout << dp[n] << endl;
    }
    time;
}