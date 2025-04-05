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
bool used[20];
int a[20], n, k;

void Try(int i){
    for(int j = 1; j <= n; ++j){
        if(!used[j]){
            used[j] = true;
            a[i] = j;
            if(i == n) {
                for(int z = 1; z <= n; ++z) cout << a[z];
                cout << ' ';
            }else Try(i + 1);
            used[j] = false;
        }
    }
}

int main(){
    boost;
    int t = 1;
    cin >> t;
    while(t--){
        memset(used, false, sizeof(used));
        cin >> n;
        Try(1);
        cout << endl;
    }
}