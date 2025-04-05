#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

int main(){
    boost;
    cin >> t;
    while(t--){
        string s; cin >> s;
        stack<int> st;
        for(int i = s.size() - 1; i >= 0; --i){
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                if(s[i] == '+') st.push(a + b);
                if(s[i] == '-') st.push(a - b);
                if(s[i] == '*') st.push(a * b);
                if(s[i] == '/') st.push(a / b);
            }
            else st.push(s[i] - '0');
        }
        cout << st.top() << endl;
    }
}