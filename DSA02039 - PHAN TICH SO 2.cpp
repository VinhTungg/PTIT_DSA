#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n;
vector<int> v;
vector<vector<int>> ans;

void Try(int i, int sum = 0){
    if(sum > n) return;
    if(sum == n) ans.push_back(v);
    for(int j = i; j >= 1; --j){
        v.push_back(j);
        Try(j, sum + j);
        v.pop_back();
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n;
        Try(n);
        cout << ans.size() << endl;
        for(auto &x : ans){
            cout << "(";
            for(int i = 0; i < x.size(); ++i){
                if(i != x.size() - 1) cout << x[i] << ' ';
                else cout << x[i];
            }
            cout << ") ";
            x.clear();
        }
        ans.clear();
        cout << endl;
    }
}