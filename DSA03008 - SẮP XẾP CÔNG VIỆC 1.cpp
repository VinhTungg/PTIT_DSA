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
        vector<pair<int, int>> v(n);
        for(auto &x : v) cin >> x.first;
        for(auto &x : v) cin >> x.second;
        sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){
            return a.second != b.second ? a.second < b.second : a.first < b.first;
        });
        int cur = 0, cnt = 0;
        for(int i = 0; i < n; ++i){
            if(cur <= v[i].first){
                ++cnt;
                cur = v[i].second;
            }
        }
        cout << cnt << endl;
    }
}