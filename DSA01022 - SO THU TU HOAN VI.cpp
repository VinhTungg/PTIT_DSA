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

void Try(int i){
    for(int j = 1; j <= n; ++j){
        if(!used[j]){
            b[i] = j;
            used[j] = true;
            if(i == n){
                ++cnt;
                if(check()){
                    cout << cnt << endl;
                    return;
                }
            }
            else Try(i + 1);
            used[j] = false;
        }
    }
}

int main(){
    boost;
    int t = 1;
    cin >> t;
    while(t--){
        cin >> n;
        memset(used, false, sizeof(used));
        for(int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        cnt = 0;
        Try(1);
    }
}