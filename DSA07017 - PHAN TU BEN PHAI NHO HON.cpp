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
        vector<int> a(n + 1), maxright(n + 1), minright(n + 1);
        for(int i = 1; i <= n; ++i) cin >> a[i];
        stack<int> st;
        st.push(n);
        maxright[n] = 0;
        for(int i = n - 1; i; --i){
            while(!st.empty() and a[i] >= a[st.top()]) st.pop();
            if(st.size()) maxright[i] = st.top();
            else maxright[i] = 0;
            st.push(i);
        }
        while(st.size()) st.pop();
        minright[n] = 0;
        st.push(n);
        for(int i = n - 1; i; --i){
            while(!st.empty() and a[i] <= a[st.top()]) st.pop();
            if(st.size()) minright[i] = st.top();
            else minright[i] = 0;
            st.push(i);
        }
        for(int i = 1; i <= n; ++i){
            if(!maxright[i] or !minright[maxright[i]]) cout << "-1 ";
            else cout << a[minright[maxright[i]]] << ' ';
        }
        cout << endl;
    }
}