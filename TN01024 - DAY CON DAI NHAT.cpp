#include <bits/stdc++.h>
#define ll long long
#define boost cin.tie(0) -> sync_with_stdio(0)
#define time cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, n;

int main() {
    boost;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<double> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
        int dp[n];
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (a[j] < a[i] and b[j] > b[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        cout << *max_element(dp, dp + n) << endl;
    }
    time;
}