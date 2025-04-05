#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

int main(){
    boost;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pair<int, int>> a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end(), cmp);
        int res = -1e9, tmp = a[0].second;
        for(int i = 1; i < n; ++i){
            if(a[i].second - tmp > res) res = a[i].second - tmp;
            tmp = min(tmp, a[i].second);
        }
        cout << res << endl;
    }
}