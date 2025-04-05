#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n, target;
int a[25];
vector<int> ans;
vector<vector<int>> res;

void Try(int i, int cur_sum = 0){
    if(cur_sum == target) {
        res.push_back(ans);
        return;
    }
    for(int j = i; j <= n; ++j){
        if(cur_sum + a[j] <= target){
            ans.push_back(a[j]);
            Try(j, cur_sum + a[j]);
            ans.pop_back();
        }
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n >> target;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        res.resize(0, vector<int>(0));
        Try(1);
        ans.clear();
        if(!res.size()) cout << "-1\n";
        else{
            cout << res.size() << ' ';
            for(auto &x : res){
                cout << "{";
                for(int i = 0; i < x.size(); ++i){
                    if(i != x.size() - 1) cout << x[i] << ' ';
                    else cout << x[i];
                }
                cout << "} ";
            }
            cout << endl;
        }
    }
}