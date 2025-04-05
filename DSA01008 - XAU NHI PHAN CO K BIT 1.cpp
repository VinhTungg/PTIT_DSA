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
int a[20], n, k;

bool check(){
    int tmp = 0;
    for(int i = 1; i <= n; ++i) if(a[i] == 1) ++tmp;
    if(tmp == k) return true;
    return false;
}

void Try(int i){
    for(int j = 0; j <= 1; ++j){
        a[i] = j;
        if(i == n){
            if(check()){
                for(int z = 1; z <= n; ++z) cout << a[z];
                cout << endl;
            }
        }else Try(i + 1);
    }
}

int main(){
    boost;
    int t = 1;
    cin >> t;
    while(t--){
        cin >> n >> k;
        Try(1);
    }
}