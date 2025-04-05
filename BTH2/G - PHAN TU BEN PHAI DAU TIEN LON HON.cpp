#include <bits/stdc++.h>
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define endl '\n'
#define MOD 1000000007

using namespace std;
int t = 1;

int main(){
    boost;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        vector<int> res(n, -1);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() and a[st.top()] < a[i]){
                res[st.top()] = a[i];
                st.pop();
            }
            st.push(i);
        }
        for(int i = 0; i < n; i++) cout << res[i] << " ";
        cout << endl;
    }
}