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
vector<int> v;
int a[1005] = {};
bool used[1005];
int n, k;

void Try(int i){
    if(i == 0) return;
    else {
        cout << "[";
        for(int j = 1; j <= i; ++j){
            if(j != i) cout << a[j] << ' ';
            else cout << a[j];
        }
        cout << "]\n";
        for(int j = 1; j < i; ++j){
            a[j] += a[j + 1];
        }
        Try(i - 1);
    }
}

int main(){
    boost;
    int t = 1;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        Try(n);
    }
}