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
string s;
int a[1005] = {}, b[1005] = {};
bool used[1005];
int n, k, cnt;

bool check(){
    for(int i = 1; i <= n; ++i){
        if(b[i] != a[i]) return false;
    }
    return true;
}

void Try(int i, int st = 1){
    for(int j = st; j <= n; ++j){
        b[i] = j;
        if(i == k){
            ++cnt;
            if(check()){
                cout << cnt << endl;
                return;
            }
        }
        else Try(i + 1, j + 1);
    }
}

int main(){
    boost;
    int t = 1;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i <= k; ++i){
            cin >> a[i];
        }
        cnt = 0;
        Try(1);
    }
}