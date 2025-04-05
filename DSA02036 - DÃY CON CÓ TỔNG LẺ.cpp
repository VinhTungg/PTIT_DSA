#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n;
int a[20];
vector<int> v;
vector<vector<int>> ans;

void Try(int i, int sum = 0){
    if(sum & 1) ans.push_back(v);
    if(i > n) return;
    for(int j = i; j <= n; ++j){
        v.push_back(a[j]);
        Try(j + 1, sum + a[j]);
        v.pop_back();
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1, greater<int>());
        Try(1);
        sort(ans.begin(), ans.end());
        for(auto &x : ans){
            for(auto &i : x) cout << i << ' ';
            cout << endl;
            x.clear();
        }
        ans.clear();
    }
}