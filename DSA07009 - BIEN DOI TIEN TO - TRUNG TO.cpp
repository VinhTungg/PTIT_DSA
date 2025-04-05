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
        stack<string> st;
        for(int i = s.size() - 1; i >= 0; i--){
            string tmp = "";
            if(s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/'){
                string a = st.top(); st.pop();
                string b = st.top(); st.pop();
                tmp = "(" + a + s[i] + b + ")";
                st.push(tmp);
            }else{
                st.push(tmp + s[i]);
            }
        }
        while(!st.empty()){
            cout << st.top();
            st.pop();
        }
        cout << endl;
    }
}