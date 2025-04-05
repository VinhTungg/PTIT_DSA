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
    string s;
    while(t--){
        cin >> s;
        int cnt1 = 0, cnt2 = 0;
        stack<char> st;
        for(auto &x : s){
            if(x == ')'){
                if(!st.empty() and st.top() == '('){
                    st.pop();
                }else{
                    st.push(x);
                }
            }else{
                st.push(x);
            }
        }
        while(!st.empty()){
            if(st.top() == '('){
                cnt1++;
            }else if(st.top() == ')'){
                cnt2++;
            }
            st.pop();
        }
        cout << (cnt1 >> 1) + (cnt2 >> 1) + (cnt1 & 1) + (cnt2 & 1) << endl;
    }
}