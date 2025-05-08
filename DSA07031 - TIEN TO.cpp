#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

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
        for(int i = n - 1; i >= 0; --i){
            if(s[i] == "+" or s[i] == "-" or s[i] == "*" or s[i] == "/"){
                ll a = st.top(); st.pop();
                ll b = st.top(); st.pop();
                st.push(calc(a, b, s[i]));
            }else st.push(stoll(s[i]));
        }
        cout << st.top() << endl;

    }
}