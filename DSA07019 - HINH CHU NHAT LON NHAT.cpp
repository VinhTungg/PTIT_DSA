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
        int n; 
        cin >> n;
        vector<ll> a(n);
        for(auto &x : a) cin >> x;
        stack<ll> st;
        ll maxArea = 0;
        for(int i = 0; i <= n; ++i){
            ll currentHeight = (i == n) ? 0 : a[i];
            while(!st.empty() and currentHeight < a[st.top()]){
                ll height = a[st.top()];
                st.pop();
                ll width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            if(i < n) st.push(i);
        }
        cout << maxArea << endl;
    }
}