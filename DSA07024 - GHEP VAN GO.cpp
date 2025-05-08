#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1;

int main(){
    boost;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        stack<int> st;
        int res = 0, i = 0;
        while(i < n){
            if(st.empty() or a[i] > a[st.top()]) st.push(i), ++i;
            else{
                int h = a[st.top()]; st.pop();
                if(st.empty()) {
                    if(h <= i) res = max(res, h);
                }
                else if(h <= (i - st.top() - 1)) res = max(res, h);
            }
        }
        while(st.size()){
            int h = a[st.top()]; st.pop();
            if(st.empty()) {
                if(h <= i) res = max(res, h);
            }
            else if(h <= (i - st.top() - 1)) res = max(res, h);
        }
        cout << res << endl;
    }
}