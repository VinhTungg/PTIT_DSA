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
        vector<pair<int, int>> a(n);
        for(auto &i : a) cin >> i.first >> i.second;
        sort(a.begin(), a.end());
        vector<int> dp(n);
        dp[0] = 1;
        for(int i = 1; i < n; i++){
            dp[i] = 1;
            for(int j = 0; j < i; j++){
                if(a[j].second < a[i].first) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        cout << *max_element(dp.begin(), dp.end()) << endl;
    }
}