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
        int n; cin >> n;
        vector<int> a(n + 1), mark(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        stack<int> st;
        for (int i = 1; i <= n; ++i) {
            while (st.size() and a[i] >= a[st.top()]) st.pop();
            mark[i] = i - (st.size() ? st.top() : 0);
            st.push(i);
        }
        for (int i = 1; i <= n; ++i) cout << mark[i] << ' ';
        cout << endl;
    }
    time;
}