#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n, S;
int a[35];
bool ok;

void Try(int i, int cur_sum = 0, int cnt = 0){
    if(ok) return;
    if(cur_sum == S) {
        ok = 1;
        cout << cnt << endl;
        return;
    }
    for(int j = i; j <= n; ++j) Try(j + 1, cur_sum + a[j], cnt + 1);
}

int main(){
    boost;
    //cin >> t;
    while(t--){
        cin >> n >> S;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1, greater<int>());
        ok = 0;
        Try(1);
        if(!ok) cout << -1;
    }
}