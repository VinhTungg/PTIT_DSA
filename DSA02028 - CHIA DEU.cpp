#include<bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n, k, dem, tmp;
int a[15], b[15];

void Try(int i, int cnt = 0){
    if(cnt == k){
        dem += i == n;
        return;
    }
    for(int j = i + 1; j <= n; ++j){
        if(b[j] - b[i] == tmp) Try(j, cnt + 1);
    }
}

int main(){
    boost;
    while(t--){
        cin >> n >> k;
        b[0] = 0;
        for(int i = 1; i <= n; ++i){
            cin >> a[i];
            b[i] = b[i - 1] + a[i];
        }
        if(b[n] % k) cout << "0";
        else{
            tmp = b[n] / k;
            Try(0);
            cout << dem;
        }
    }
}
