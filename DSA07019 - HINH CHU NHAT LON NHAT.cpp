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
        vector<ll> a(n);
        for(auto &x : a) cin >> x;
        ll maxArea = 0;
        stack<int> st;
        for(int i = 0; i < n; ++i){
            if(st.empty() or a[i] >= a[st.top()]) st.push(i);
            else{
                int tmp = st.top();
                st.pop();
                ll cur_area = (st.empty() ? a[tmp] * i : a[tmp] * (i - st.top() - 1));
                maxArea = max(maxArea, cur_area);
            }
        }
        int i = n;
        if(maxArea == 0){
            int tmp = st.top();
            st.pop();
            ll cur_area = (st.empty() ? a[tmp] * i : a[tmp] * (i - st.top() - 1));
            maxArea = max(maxArea, cur_area);
        }
        cout << maxArea << endl;
    }
}