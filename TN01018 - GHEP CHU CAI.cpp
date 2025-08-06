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
char c;
vector<int> vs;

bool check(string s) {
    for (int i = 1; i < s.size() - 1; ++i) {
        if (s[i] == 'A' and s[i - 1] != 'E' and s[i + 1] != 'E') return false;
        if (s[i] == 'E' and s[i - 1] != 'A' and s[i + 1] != 'A') return false;
    }
    return true;
}

void Try(int i, string s = "") {
    if (i == n) {
        if (check(s)) cout << s << endl;
        return;
    }
    for (char j = 'A'; j <= c; ++j) {
        if (!vs[j - 'A']) {
            vs[j - 'A'] = 1;
            Try(i + 1, s + j);
            vs[j - 'A'] = 0;
        }
    }
}

int main() {
    boost;
    //cin >> t;
    while (t--) {
        cin >> c;
        n = c - 'A' + 1;
        vs.assign(n, 0);
        Try(0);
    }
    time;
}