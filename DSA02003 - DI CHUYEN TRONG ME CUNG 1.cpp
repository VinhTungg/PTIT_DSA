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
vector<string> v;
int a[1005][1005] = {};
bool used[1005];
int n, k;

void Try(int i, int j){
    if(!a[i][j]) return;
    if(i == n && j == n){
        v.push_back(s);
        return;
    }
    if(i <= n - 1 && a[i + 1][j]){
        s += 'D';
        Try(i + 1, j);
        s.pop_back();
    }
    if(j <= n - 1 && a[i][j + 1]){
        s += 'R';
        Try(i, j + 1);
        s.pop_back();
    }
}

int main(){
    boost;
    int t = 1;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j) cin >> a[i][j];
        }
        Try(1, 1);
        if(v.empty()) cout << "-1";
        else{
            for(auto &s : v) cout << s << ' ';
        }
        cout << endl;
        v.clear();
    }
}