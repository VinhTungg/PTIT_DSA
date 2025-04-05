#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n;
int X[15];
bool vs[15];

bool check(int a[], int n){
    for(int i = 2; i <= n; ++i) if(abs(a[i] - a[i - 1]) == 1) return false;
    return true;
}

void Try(int i){
    for(int j = 1; j <= n; ++j){
        if(!vs[j]){
            vs[j] = 1;
            X[i] = j;
            if(i == n){
                if(check(X, n)) {
                    for(int z = 1; z <= n; ++z) cout << X[z];
                    cout << endl;
                }
            }else if(i < n) Try(i + 1);
            vs[j] = 0;
        }
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n;
        Try(1);
        cout << endl;
    }
}