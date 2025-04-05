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
vector<int> v(1, 0), a;
bool used[1005];
int n, k;

void Try(int i){
    for(int j = a[i - 1] + 1; j <= n - k + i; ++j){
        a[i] = j;
        if(i == k){
            for(int z = 1; z <= k; ++z) cout << v[a[z]] << ' ';
            cout << endl;
        }else Try(i + 1);
    }
}

int main(){
    boost;
    int t = 1;
    //cin >> t;
    while(t--){
        cin >> n >> k;
        memset(used, 0, sizeof(used));
        for(int i = 1; i <= n; ++i){
            int x; cin >> x;
            if(!used[x]){
                used[x] = 1;
                v.pb(x);
            }
        }
        sort(all(v));
        n = v.size() - 1;
        a.resize(v.size());
        Try(1);
    }
}