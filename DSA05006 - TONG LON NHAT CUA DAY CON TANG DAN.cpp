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
        vector<int> a(n + 1), dp(n + 1, 0);
        for(int i = 1; i <= n; ++i) cin >> a[i];
        for(int i = 1; i <= n; ++i){
            dp[i] = a[i];
            for(int j = 1; j < i; ++j){
                if(a[i] > a[j]) dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
        cout << *max_element(dp.begin() + 1, dp.begin() + n + 1) << endl;
    }
}