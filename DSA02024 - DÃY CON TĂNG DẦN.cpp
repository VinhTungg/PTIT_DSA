#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n;
int a[25];
vector<string> v;
vector<int> save;

void Try(int i){
    for(int j = i + 1; j <= n; ++j){
        if(a[i] < a[j]){
            save.push_back(a[j]);
            if(save.size() >= 2){
                string s = "";
                for(auto &x : save) s += to_string(x) + ' ';
                v.push_back(s);
            }
            Try(j);
            save.pop_back();
        }
    }
}

int main(){
    //cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        Try(0);
        sort(v.begin(), v.end());
        for(auto &x : v){
            cout << x << endl;
        }
    }
}