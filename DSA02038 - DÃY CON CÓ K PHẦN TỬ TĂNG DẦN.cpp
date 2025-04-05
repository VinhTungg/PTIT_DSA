#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n, k;
int a[20], X[20];

void Try(int i){
    for(int j = X[i - 1] + 1; j <= n - k + i; ++j){
        X[i] = j;
        if(i == k){
            for(int z = 1; z <= k; ++z) cout << a[X[z]] << ' ';
            cout << endl;
        }else if(i < k) Try(i + 1);
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        Try(1);
    }
}