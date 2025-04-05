#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n, S, ans;
int a[35];
bool vs[35]{};

void Try(int cur_sum = 0, int cnt = 0){
    if(cur_sum == S) ans = min(ans, cnt);
    for(int j = 1; j <= n; ++j){
        if(!vs[j]){
            vs[j] = 1;
            if(cur_sum + a[j] <= S) Try(cur_sum + a[j], cnt + 1);
            vs[j] = 0;
        }
    }
}

int main(){
    boost;
    //cin >> t;
    while(t--){
        cin >> n >> S;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        ans = 1e9;
        Try(1);
        cout << ans;
    }
}