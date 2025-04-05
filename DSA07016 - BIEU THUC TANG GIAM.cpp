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
        for(int i = 1; i <= s.size() + 1; ++i){
            st.push(i);
            if(s[i - 1] == 'I'){
                while(!st.empty()){
                    cout << st.top();
                    st.pop();
                }
            } 
        }
        while(!st.empty()){
            cout << st.top();
            st.pop();
        }
        cout << endl;
    }
}