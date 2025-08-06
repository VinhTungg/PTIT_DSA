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

bool check(string s) {
    if (s[0] != '8' || s[s.size() - 1] != '6') return false;
    int cnt6 = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '6') {
            ++cnt6;
            if (cnt6 > 3) return false;
        } else {
            cnt6 = 0;
        }
        if (s[i] == '8' and i + 1 < s.size() and s[i + 1] == '8') {
            return false;
        }
    }
    return true;
}

void Try(int i, string s) {
    if (i == n) {
        if (check(s)) {
            cout << s << endl;
        }
        return;
    }
    Try(i + 1, s + "6");
    Try(i + 1, s + "8");
}

int main() {
    boost;
    //cin >> t;
    while (t--) {
        cin >> n;
        Try(0, "");
    }
    time;
}