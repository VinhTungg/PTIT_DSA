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
        vector<int> a(n + 1);
        int sum = 0;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        if(sum & 1){
            cout << "NO" << endl;
            continue;
        }else{
            sum >>= 1;
            bool dp[sum + 1]{}; dp[0] = 1;
            for(int i = 1; i <= n; ++i){
                for(int j = sum; j >= a[i]; --j){
                    dp[j] |= dp[j - a[i]];
                }
            }
            cout << (dp[sum] ? "YES" : "NO") << endl;
        }
    }
}