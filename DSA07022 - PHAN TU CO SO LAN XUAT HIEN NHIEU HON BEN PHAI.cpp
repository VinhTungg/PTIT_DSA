#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1;
const int MAX = 1e6 + 1;
int F[MAX];

int main(){
    boost;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n), ans;
        memset(F, 0, sizeof(F));
        for (auto &x : v) {
            cin >> x; 
            ++F[x];
        }
        stack<int> st;
        st.push(n - 1);
        ans.insert(ans.begin(), -1);
        for (int i = n - 2; ~i; --i) {
            while (st.size() and F[v[i]] >= F[v[st.top()]]) st.pop();
            if (st.empty()) ans.insert(ans.begin(), -1);
            else ans.insert(ans.begin(), v[st.top()]);
            st.push(i);
        }
        for (auto &x : ans) cout << x << ' ';
        cout << endl;
    }
}