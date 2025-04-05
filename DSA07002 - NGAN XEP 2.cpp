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
    stack<int> st;
    while(t--){
        string s;
        cin >> s;
        if(s == "PUSH"){
            int n;
            cin >> n;
            st.push(n);
        }else if(s == "POP"){
            if(!st.empty()){
                st.pop();
            }
        }else{
            if(!st.empty()){
                cout << st.top() << endl;
            }else{
                cout << "NONE" << endl;
            }
        }
    }
}