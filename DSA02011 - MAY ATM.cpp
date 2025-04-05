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
string s;
vector<string> v;
int a[1005] = {}, b[1005] = {};
bool used[1005];
int n, k, ans;

void Try(int i, int st = 1, int sum = 0){
    if(sum == k){
        ans = min(ans, i - 1);
        return;
    }
    if(sum > k) return;
    for(int j = st; j <= n; ++j){
        Try(i + 1, j + 1, sum + a[j]);
    }
}

int main(){
    boost;
    int t = 1;
    cin >> t;
    while(t--){
        cin >> n >> k;
        ans = 1e9;
        for(int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        sort(a + 1, a + n + 1, greater<int>());
        Try(1);
        if(ans != 1e9) cout << ans << endl;
        else cout << "-1\n";
    }
}