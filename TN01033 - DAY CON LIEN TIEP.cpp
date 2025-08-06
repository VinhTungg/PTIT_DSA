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
    //cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int &i : a) cin >> i;
        int max_num = *max_element(a.begin(), a.end());
        int i = 0, max_len = 1;
        while (i < n - 1) {
            int len = 1;
            while (a[i] == a[i + 1] and a[i] == max_num) {
                ++len;
                ++i;
            }
            max_len = max(max_len, len);
            ++i;
        }
        cout << max_len;
    }
    time;
}