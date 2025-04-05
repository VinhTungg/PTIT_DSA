#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n, k;
int X[10];
vector<string> v;

int calc(vector<string> v, int X[]){
    int min_num = 1e8, max_num = 0;
    for(auto &x : v){
        string tmp = "";
        for(int i = 0; i < x.size(); ++i) tmp += x[X[i]];
        min_num = min(min_num, stoi(tmp));
        max_num = max(max_num, stoi(tmp));
    }
    return max_num - min_num;
}

int main(){
    boost;
    //cin >> t;
    while(t--){
        cin >> n >> k;
        v.resize(n);
        for(auto &x : v) cin >> x;
        for(int i = 0; i < k; ++i) X[i] = i;
        int res = 1e8;
        do{
            res = min(res, calc(v, X));
        }while(next_permutation(X, X + k));
        cout << res;
    }
}