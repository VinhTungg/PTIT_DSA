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
        stack<char> st;
        int ans = 0;
        for(auto &i : s){
            if(i == '(') st.push(i);
            else{
                if(!st.empty() and st.top() == ')' or st.empty()) st.push(i);
                else{
                    st.pop();
                    ans += 2;
                }
            }
        }
        cout << ans << endl;
    }
}