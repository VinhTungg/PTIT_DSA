#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

int calc(int a, int b, char c){
    if(c == '+') return a + b;
    if(c == '-') return a - b;
    if(c == '*') return a * b;
    return a / b;
}

int main(){
    boost;
    cin >> t;
    while(t--){
        string s; cin >> s;
        stack<int> st;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/'){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(calc(b, a, s[i]));
            }else{
                st.push(s[i] - '0');
            }
        }
        cout << st.top() << endl;
    }
}