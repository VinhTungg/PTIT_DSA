#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

int main(){
    boost;
    // cin >> t;
    while(t--){
        string s;
        stack<int> st;
        while(cin >> s){
            if(s[0] == 'p' && s[1] == 'u'){
                int n;
                cin >> n;
                st.push(n);
            }else if(s[0] == 'p' && s[1] == 'o'){
                if(!st.empty()){
                    st.pop();
                }
            }else{
                if(!st.empty()){
                    stack<int> tmp;
                    while(st.size()){
                        tmp.push(st.top());
                        st.pop();
                    }
                    while(tmp.size()){
                        cout << tmp.top() << ' ';
                        st.push(tmp.top());
                        tmp.pop();
                    }
                    cout << endl;
                }else{
                    cout << "empty" << endl;
                }
            }
        }
    }
}