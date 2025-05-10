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
        string s; cin >> s;
        stack<ll> st;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/'){
                ll b = st.top(); st.pop();
                ll a = st.top(); st.pop();
                if(s[i] == '+') st.push(a + b);
                if(s[i] == '-') st.push(a - b);
                if(s[i] == '*') st.push(a * b);
                if(s[i] == '/') st.push(a / b);
            }else st.push(s[i] - '0');
        }
        cout << st.top() << endl;
    }
}