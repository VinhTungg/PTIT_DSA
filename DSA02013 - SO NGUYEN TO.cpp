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
// string s = "";
vector<int> v, tmp;
vector<vector<int>> ans;
int a[1005][1005] = {};
bool used[1005] = {};
int s, p, n, m;

void init(){
    for(int i = 2; i <= sqrt(200); ++i){
        if(!used[i]){
            for(int j = 2 * i; j <= 200; j += i){
                used[j] = 1;
            }
        }
    }
    for(int i = 2; i <= 200; ++i){
        if(!used[i]) v.push_back(i);
    }
}

void Try(int i, int sum = 0){
    if(tmp.size() > n or sum > s) return;
    if(sum == s){
        if(tmp.size() == n) ans.push_back(tmp);
        return;
    }
    for(int j = i; j < v.size(); ++j){
        if(v[j] < s){
            tmp.push_back(v[j]);
            if (sum + v[j] <= s) Try(j + 1, sum + v[j]);
            tmp.pop_back();
        }
    }
}

int main(){
    boost;
    int t = 1;
    cin >> t;
    init();
    while(t--){
        cin >> n >> p >> s;
        int st = upper_bound(all(v), p) - v.begin();
        Try(st);
        cout << ans.size() << endl;
        for(auto &x : ans) {
            for(auto &num : x) cout << num << ' ';
            cout << endl;
        }
        ans.clear();
        tmp.clear();
    }
}