#include <bits/stdc++.h>
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define endl '\n'
#define MOD 1000000007

using namespace std;
int t = 1;

int main(){
    boost;
    cin >> t;
    while(t--){
        string s; cin >> s;
        stack<string> st;
        for(int i = s.size() - 1; i >= 0; --i){
            if(s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/'){
                string a = st.top(); st.pop();
                string b = st.top(); st.pop();
                string tmp = "(" + a + s[i] + b + ")";
                st.push(tmp);
            }
            else st.push(string(1, s[i]));
        }
        cout << st.top() << endl;
    }
}