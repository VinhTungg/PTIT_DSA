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
        int n, s;
        cin >> n >> s;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; ++i) cin >> a[i];
        bool dp[s + 1]{}; dp[0] = 1;
        for(int i = 1; i <= n; ++i){
            for(int j = s; j >= a[i]; --j){
                dp[j] |= dp[j - a[i]];
            }
        }
        cout << (dp[s] ? "YES" : "NO") << endl;
    }
}