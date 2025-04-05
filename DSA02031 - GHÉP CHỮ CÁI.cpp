#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n;
char alpha;
int X[15]{};
bool vs[20];
string s;

bool check(int a[], int n){
    if(a[1] == 1 and a[n] == 5 or a[1] == 5 and a[n] == 1) return true;
    for(int i = 2; i <= n; ++i) if(a[i - 1] == 1 and a[i] == 5 or a[i - 1] == 5 and a[i] == 1) return true;
    return false;
}

void Try(int i){
    for(int j = 1; j <= n; ++j){
        if(!vs[j]){
            vs[j] = 1;
            X[i] = j;
            if(i == n) {
                if(n < 5){
                    if(X[1] == 1 or X[i] == 1){
                        for(int z = 1; z <= i; ++z) cout << s[X[z] - 1];
                        cout << endl;
                    }
                }else{
                    if(check(X, n)){
                        for(int z = 1; z <= i; ++z) cout << s[X[z] - 1];
                        cout << endl;
                    }
                }
            } else if(i < n) Try(i + 1);
            vs[j] = 0;
        } 
    }
}

int main(){
    boost;
    //cin >> t;
    while(t--){
        cin >> alpha;
        s = "";
        for(int i = 0; i <= alpha - 'A'; ++i)
            s += (i + 'A');
        n = alpha - 'A' + 1;
        Try(1);
    }
}