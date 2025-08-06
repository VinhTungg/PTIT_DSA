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
vector<int> a;

bool check() {
    for (int i = 1; i < n; ++i) if (abs(a[i] - a[i + 1]) == 1) return false;
    return true;
}

int main() {
    boost;
    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n + 1);
        for (int i = 1; i <= n; ++i) a[i] = i;
        do {
            if (check()) {
                for (int i = 1; i <= n; ++i) cout << a[i];
                cout << endl;
            }
        } while (next_permutation(a.begin() + 1, a.end()));
    }
    time;
}