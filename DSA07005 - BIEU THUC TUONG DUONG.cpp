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
        stack<pair<int, int>> st;
        vector<int> sign(s.size(), 1);
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                int currentSign = 1;
                if(i and s[i - 1] == '-'){
                    currentSign = -1;
                }
                int effSign = 1;
                if(!st.empty()){
                    effSign = st.top().second;
                }
                st.push({i, effSign * currentSign});
            }
            else if(s[i] == ')'){
                if(!st.empty()){
                    st.pop();
                }
            }
            else if(s[i] == '+' || s[i] == '-'){
                int effSign = 1;
                if(!st.empty()){
                    effSign = st.top().second;
                }
                if(effSign == -1){
                    sign[i] = -1;
                }
            }
        }
        string result = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == ')'){
                continue;
            }
            else if(s[i] == '+'){
                if(sign[i] == -1){
                    result += '-';
                }
                else{
                    result += '+';
                }
            }
            else if(s[i] == '-'){
                if(sign[i] == -1){
                    result += '+';
                }
                else{
                    result += '-';
                }
            }
            else{
                result += s[i];
            }
        }
        cout << result << endl;
    }
}