#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n;
vector<int> a;
vector<vector<int>> ans;

bool check(vector<int> a){
    if(a[1] == 1) return false;
    if(a[n] == 0) return false;
    for(int i = 1; i < n; ++i){
        if(a[i] == a[i + 1] and a[i] == 0) return false;
    }
    return true;
}

void Try(int i){
    for(int j = 0; j <= 1; ++j){
        a[i] = j;
        if(i == n){
            if(check(a)){
                ans.push_back(a);
                return;
            }
        }
        else if(i < n) Try(i + 1);
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n;
        a.resize(n + 1);
        Try(1);
        for(auto &x : ans){
            for(int i = 1; i <= n; ++i){
                if(!x[i]) cout << "H";
                else cout << "A";
            }
            cout << endl;
            x.clear();
        }
    }
}