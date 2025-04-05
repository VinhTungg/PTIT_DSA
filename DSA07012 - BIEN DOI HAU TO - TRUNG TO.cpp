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
        for(auto &x : s){
            if(isalpha(x)) st.push(string(1, x));
            else{
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
                st.push('(' + op2 + string(1, x) + op1 + ')');
            }
        }
        while(!st.empty()){
            cout << st.top();
            st.pop();
        }
        cout << endl;
    }
}