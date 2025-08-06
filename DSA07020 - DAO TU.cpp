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
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        vector<string> v;
        stack<char> st;
        stringstream ss(s);
        while (ss >> s) v.emplace_back(s);
        for (auto &x : v) {
            for (auto &y : x) st.push(y);
            s = "";
            while (st.size()) s += st.top(), st.pop();
            x = s;
        }
        for (auto &x : v) cout << x << ' ';
        cout << endl;
    }
    time;
}