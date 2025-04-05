#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n;
string s;
char X[20];
bool vs[20];

void Try(int i, int st = 1){
    for(int j = i; j <= n; ++j){
        X[st] = s[j];
        if(!vs[j]){
            vs[j] = 1;
            for(int z = 1; z <= st; ++z) cout << X[z];
            cout << ' ';
            Try(j + 1, st + 1);
            vs[j] = 0;
        }
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n >> s;
        memset(vs, 0, sizeof(vs));
        s = "0" + s;
        Try(1);
        cout << endl;
    }
}