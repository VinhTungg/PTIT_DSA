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
char a[10];
int b[10];

void Try (int i, int st = 1) {
    if (i == n) {
        for (int j = 0; j < n; ++j) cout << a[j];
        for (int j = 0; j < n; ++j) cout << b[j];
        cout << endl;
        return;
    }
    for (int j = 1; j <= n; ++j) {
        b[i] = j;
        Try(i + 1, j);
    }
}

int main() {
    boost;
    //cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) a[i] = i + 'A';
        do {
            Try(0);
        } while (next_permutation(a, a + n));
    }
    time;
}