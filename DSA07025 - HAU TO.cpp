#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1;

ll calc(ll a, ll b, string c){
    if(c == "+") return a + b;
    if(c == "-") return a - b;
    if(c == "*") return a * b;
    return a / b;
}

int main(){
    boost;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<string> s(n);
        for(int i = 0; i < n; ++i) cin >> s[i];
        stack<ll> st;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == "+" or s[i] == "-" or s[i] == "*" or s[i] == "/"){
                ll b = st.top(); st.pop();
                ll a = st.top(); st.pop();
                st.push(calc(a, b, s[i]));
            }else st.push(stoll(s[i]));
        }
        cout << st.top() << endl;
    }
}