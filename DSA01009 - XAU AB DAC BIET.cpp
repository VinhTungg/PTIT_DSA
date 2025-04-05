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
int n, k;
vector<int> a(20);
vector<vector<int>> res;

bool check(){
    int tmp = 0, res = 0;
    for(int i = 1; i <= n; ++i){
        if(!a[i]) ++tmp;
        else tmp = 0;
        if(tmp >= k) ++res;
    }
    return res == 1;
}

void Try(int i){
    for(int j = 0; j <= 1; ++j){
        a[i] = j;
        if(i == n){
            if(check()){
                res.pb(a);
            }
        }else Try(i + 1);
    }
}

int main(){
    boost;
    int t = 1;
    //cin >> t;
    while(t--){
        cin >> n >> k;
        Try(1);
        cout << res.size() << endl;
        for(auto &x : res){
            for(int i = 1; i <= n; ++i){
                cout << char(x[i] + 'A');
            }
            cout << endl;
            x.clear();
        }
    }
}