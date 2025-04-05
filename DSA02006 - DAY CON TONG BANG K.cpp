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
vector<string> v;
int a[1005] = {}, b[1005] = {};
bool used[1005], ok = 0;
int n, k;

void Try(int i, int sum, int st = 1){
    for(int j = st; j <= n; ++j){
        b[i] = a[j];
        if(sum + b[i] == k){
            ok = 1;
            cout << "[";
            for(int z = 1; z <= i; ++z){
                if(z != i) cout << b[z] << ' ';
                else cout << b[z];
            }
            cout << "] ";
        }else if(sum + b[i] <= k) Try(i + 1, sum + b[i], j + 1);
    }
}

int main(){
    boost;
    int t = 1;
    cin >> t;
    while(t--){
        ok = 0;
        memset(b, 0, sizeof(b));
        cin >> n >> k;
        for(int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        Try(1, 0);
        if(!ok) cout << -1;
        cout << endl;
    }
}