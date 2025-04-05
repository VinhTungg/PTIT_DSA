#include <bits/stdc++.h>
#define ll long long
#define foru(i,a,b) for(int i = a; i <= b; ++i)
#define ford(i,a,b) for(int i = a; i >= b; --i)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define endl "\n"
#define sz size
#define all(a) a.begin(), a.end()
#define MOD 1000000007

using namespace std;
int n, k;
int a[1005] = {};
vector<bool> used(1005, false);
vector<int> s;
vector<vector<int>> ans;

void Try(int i, int sum){
    for(int j = i; j <= n; ++j){
        if(!used[a[j]]){
            used[a[j]] = true;
            s.push_back(a[j]);
            if(sum + a[j] == k){
                ans.push_back(s);
            }else if(a[j + 1] + sum <= k) Try(j + 1, sum + a[j]);
            s.pop_back();
            used[a[j]] = false;
        }
    }
}

int main(){
    boost;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    Try(1, 0);
    reverse(ans.begin(), ans.end());
    for(auto &x : ans){
        for(auto &num : x) cout << num << ' ';
        cout << endl;
    }
    cout << ans.size();
}