#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n;
vector<int> a;

void out(int j){
    cout << "[";
    for(int i = j; i <= n; ++i){
        if(i != n) cout << a[i] << ' ';
        else cout << a[i];
    }
    cout << "]\n";
}

void Try(int i){
    for(int j = i; j <= n; ++j){
        out(j);
        a[i + 1] += a[i];
        Try(i + 1);
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n;
        a.resize(n + 1);
        for(int i = 1; i <= n; ++i) cin >> a[i];
        Try(1);
    }
}