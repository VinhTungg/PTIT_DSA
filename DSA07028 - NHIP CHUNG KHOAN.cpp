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
        int n; cin >> n;
        vector<int> a(n + 1), tmp(n + 1);
        for(int i = 1; i <= n; ++i) cin >> a[i];
        stack<int> st;
        for(int i = 1; i <= n; ++i){
            while(!st.empty() and a[i] >= a[st.top()]) st.pop();
            if(st.empty()) tmp[i] = 0;
            else tmp[i] = st.top();
            st.push(i);
        }
        for(int i = 1; i <= n; ++i) cout << i - tmp[i] << ' ';
        cout << endl;
    }
}