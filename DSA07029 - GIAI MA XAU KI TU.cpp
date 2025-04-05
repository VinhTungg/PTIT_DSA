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
        stack<string> st;
        string ans = "";
        for(int i = 0; i < s.size(); ++i){
            if(isdigit(s[i])){
                int tmp = 0;
                while(isdigit(s[i])){
                    tmp = tmp * 10 + (s[i] - '0');
                    ++i;
                }
                --i;
                st.push(to_string(tmp));
            }else if(s[i] == ']'){
                string decode = "";
                while(!st.empty() and st.top() != "["){
                    decode = st.top() + decode;
                    st.pop();
                }
                if(!st.empty()) st.pop();
                int re = 1;
                if(!st.empty() && !st.top().empty() && isdigit(st.top()[0])){
                    re = stoi(st.top());
                    st.pop();
                }
                string repeated = "";
                for(int j = 0; j < re; ++j) repeated += decode;
                st.push(repeated);
            }else st.push(string(1, s[i]));
        }
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        cout << ans << endl;
    }
}