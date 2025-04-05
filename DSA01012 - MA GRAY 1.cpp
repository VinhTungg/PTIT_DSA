#include <bits/stdc++.h>
#define ll long long
#define foru(i,a,b) for(int i = a; i <= b; ++i)
#define ford(i,a,b) for(int i = a; i >= b; --i)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define endl "\n"
#define sz size
#define all(a) a.begin(), a.end()
#define MOD 1000000007

using namespace std;
int n, a[15] = {};

void sinh(){
    int i = n; 
    while(i > 0 && a[i] == 1){
        --i;
    }
    a[i] = 1;
    for(int j = i + 1; j <= n; ++j) a[j] = 0;
}

int main(){
    boost;
    int t = 1;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= pow(2, n); ++i){
            int x = a[1];
            cout << x;
            for(int j = 2; j <= n; ++j){
                x = a[j] ^ a[j - 1];
                cout << x;
            }
            sinh();
            cout << ' ';
        }
        cout << endl;
    }
}