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
        stack<int> st;
        vector<int> ans;
        int idx = 1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(idx);
                ans.emplace_back(idx++);
            } 
            else if (s[i] == ')') {
                ans.emplace_back(st.top());
                st.pop();
            }
        }
        for (int &x : ans) cout << x << ' ';
        cout << endl;
    }
    time;
}