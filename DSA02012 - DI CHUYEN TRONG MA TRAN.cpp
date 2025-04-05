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
string s = "";
vector<int> v;
int a[1005][1005] = {};
bool used[1005];
int n, k, m, cnt;

void Try(int i, int j){
    if(i == n && j == m) ++cnt;
    if(i < n) Try(i + 1, j);
    if(j < m) Try(i, j + 1);
}

int main(){
    boost;
    int t = 1;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j) cin >> a[i][j];
        }
        cnt = 0;
        Try(1, 1);
        cout << cnt << endl;
    }
}