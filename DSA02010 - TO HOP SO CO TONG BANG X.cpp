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
bool used[1005], ok;
int n, k;

void Try(int i, int st = 1, int sum = 0){
    for(int j = st; j <= n; ++j){
        if(sum + a[j] <= k){
            b[i] = a[j];
            if(sum + a[j] == k){
                ok = true;
                cout << "[";
                for(int z = 1; z <= i; ++z){
                    if(z != i) cout << b[z] << ' ';
                    else cout << b[z];
                }
                cout << "]";
            }else Try(i + 1, j, sum + a[j]);
        }
    }
}

int main(){
    boost;
    int t = 1;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        ok = false;
        Try(1);
        if(!ok) cout << "-1";
        cout << endl;
    }
}