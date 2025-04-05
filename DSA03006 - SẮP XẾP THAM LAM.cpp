#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

bool check(vector<int> v, vector<int> tmp){
    for(int i = 0; i < v.size(); ++i){
        if(v[i] != tmp[i] and v[i] != tmp[v.size() - i - 1]) return false;
    }
    return true;
}

int main(){
    boost;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n), tmp(n);
        for(auto &x : v) cin >> x;
        tmp = v;
        sort(tmp.begin(), tmp.end());
        cout << (check(v, tmp) ? "Yes\n" : "No\n");
    }
}