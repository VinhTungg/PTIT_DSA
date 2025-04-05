#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

int priority(char c){
    if(c == '+' or c == '-') return 1;
    else if(c == '*' or c == '/') return 2;
    else if(c == '^') return 3;
    return -1;
}

int main(){
    boost;
    cin >> t;
    while(t--){
        string s; cin >> s;
        string ans = "";
        stack<char> st;
        for(auto &x : s){
            if(isalpha(x)) ans += x;
            else if(x == '(') st.push(x);
            else if(x == ')'){
                while(!st.empty() && st.top() != '('){
                    ans += st.top();
                    st.pop();
                }
                if(!st.empty()) st.pop();
            }else{
                while(!st.empty() && st.top() != '(' && priority(st.top()) >= priority(x)){
                    ans += st.top();
                    st.pop();
                }
                st.push(x);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        cout << ans << endl;
    }
}
