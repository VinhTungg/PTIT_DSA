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
vector<string> v;
string s;
int a[1005] = {};
bool used[1005];
int n, k;

void Try(int i, int st = 0){
    for(int j = st; j < n; ++j){
        a[i] = j;
        if(i == k - 1){
            for(int z = 0; z < k; ++z) cout << v[a[z]] << ' ';
            cout << endl;
        }else Try(i + 1, j + 1);
    }
}

int main(){
    boost;
    int t = 1;
    //cin >> t;
    while(t--){
        cin >> n >> k; 
        set<string> se;
        for(int i = 1; i <= n; ++i){
            cin >> s;
            se.insert(s);
        }
        n = se.size();
        for(auto &x : se) v.push_back(x);
        Try(0);
    }
}