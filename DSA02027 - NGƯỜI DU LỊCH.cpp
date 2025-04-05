#include<bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n, val, ans;
int a[20][20], X[20];
bool visited[20];

void Try(int i, int sum = 0, int cnt = 1){
    if(sum >= ans) return;
    if(cnt == n){
        ans = min(ans, sum + a[i][1]);
        return;
    }
    for(int j = 2; j <= n; ++j){
        if(!visited[j]){
            visited[j] = 1;
            if(sum + (n - cnt + 1) * val < ans) Try(j, sum + a[i][j], cnt + 1);
            visited[j] = 0;
        }
    }
}

int main(){
    boost;
    //cin >> t;
    while(t--){
        cin >> n;
        val = 1e8, ans = 1e8;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                cin >> a[i][j];
                val = min(val, a[i][j]);
            }
        }
        visited[1] = 1;
        Try(1);
        cout << ans << endl;
    }
}
