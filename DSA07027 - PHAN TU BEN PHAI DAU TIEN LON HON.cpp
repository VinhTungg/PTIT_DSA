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
        vector<int> a(n), res;
        for(auto &i : a) cin >> i;
        stack<int> st;
        st.push(a[n - 1]);
        res.push_back(-1);
        for(int i = n - 2; i >= 0; --i){
            if(a[i] < st.top()) res.push_back(st.top());
            else{
                while(!st.empty() && a[i] >= st.top()) st.pop();
                if(st.empty()) res.push_back(-1);
                else res.push_back(st.top());
            }
            st.push(a[i]);
        }
        for(int i = res.size() - 1; i >= 0; --i) cout << res[i] << " ";
        cout << endl;
    }
}