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
        vector<pair<int, int>> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
        sort(a.begin(), a.end(), [](pair<int, int> x, pair<int, int> y){
            return x.second < y.second;
        });
        int cnt = 1, end = a[0].second;
        for(int i = 0; i < n - 1; ++i){
            if(end <= a[i + 1].first){
                end = a[i + 1].second;
                ++cnt;
            }
        }
        cout << cnt << endl;
    }
}