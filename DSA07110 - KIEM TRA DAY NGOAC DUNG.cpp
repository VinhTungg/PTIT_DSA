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
        string s;
        cin >> s;
        if(!s.size()){
            cout << "YES" << endl;
            continue;
        }else{
            bool ok = 1;
            stack<char> st;
            for(auto &x : s){
                if(x == '(' || x == '[' || x == '{'){
                    st.push(x);
                }else{
                    if(st.empty()){
                        cout << "NO" << endl;
                        ok = 0;
                        break;
                    }else{
                        if(x == ')' && st.top() == '('){
                            st.pop();
                        }else if(x == ']' && st.top() == '['){
                            st.pop();
                        }else if(x == '}' && st.top() == '{'){
                            st.pop();
                        }else{
                            ok = 0;
                            cout << "NO" << endl;
                            break;
                        }
                    }
                }
            }
            if(ok && st.empty()){
                cout << "YES" << endl;
            }
        }
    }
}