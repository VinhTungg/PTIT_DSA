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
    cin.ignore();
    while(t--){
        stack<char> st;
        string s; 
        getline(cin, s);
        bool check = false;
        int ok = 0;
        for(auto &x : s){
            if(x == '(' or x == '+' or x == '-' or x == '*' or x == '/'){
                st.push(x);
            }else if(x == ')'){
                while(!st.empty() and st.top() != '('){
                    if(st.top() == '+' or st.top() == '-' or st.top() == '*' or st.top() == '/'){
                        ok = 1;
                    }
                    st.pop();
                }
                if(!ok){
                    check = true;
                    cout << "Yes" << endl;
                    break;
                }
                ok = 0;
                if(!st.empty()) st.pop();
            }
        }
        if(!check){
            cout << "No" << endl;
        }
    }
}