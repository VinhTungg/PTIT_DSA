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
        st.push(-1);
        int res = -1;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '(') st.push(i);
            else{
                st.pop();
                if(!st.empty()) res = max(res, i - st.top());
                else st.push(i);
            }
        }
        cout << res << endl;
    }
}