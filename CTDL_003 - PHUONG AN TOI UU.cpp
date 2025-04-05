#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, Fopt, n, w;
vector<int> a, c, Xopt, tmp;

void Try(int i){
    for(int j = 0; j <= 1; ++j){
        tmp[i] = j;
        if(i == n){
            int sum = 0, weight = 0;
            for(int z = 1; z <= n; ++z){
                if(tmp[z]){
                    weight += a[z];
                    sum += c[z];
                }
            }
            if(weight <= w and Fopt < sum){
                Fopt = sum;
                Xopt = tmp;
            }
        }else if(i < n) Try(i + 1);
    }
}

int main(){
    boost;
    //cin >> t;
    while(t--){
        cin >> n >> w;
        a.resize(n + 1); c.resize(n + 1); Xopt.resize(n + 1); tmp.resize(n + 1);
        for(int i = 1; i <= n; ++i) cin >> c[i];
        for(int i = 1; i <= n; ++i) cin >> a[i];
        Fopt = INT_MIN;
        Try(1);
        cout << Fopt << endl;
        for(int i = 1; i <= n; ++i){
            cout << Xopt[i] << ' ';
        }
        cout << endl;
    }
}