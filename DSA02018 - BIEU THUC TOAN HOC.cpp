#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, dk;
vector<int> a(3), X(5);
vector<vector<int>> v, config;
string Symbol = "+-*";

int calc(int a, int b, char c){
    if(c == '+') return a + b;
    else if(c == '-') return a - b;
    else return a * b;
}

void TryOps(vector<int> &ops, int i){
    if(i == 4){
        v.push_back(ops);
        return;
    }
    for(int j = 0; j < 3; ++j){
        ops[i] = j;
        TryOps(ops, i + 1);
    }
}

bool solve(){
    for (auto &i : config){
        for (auto &j : v){
            int ans = i[0];
            for (int k = 1; k <= 4; ++k) ans = calc(ans, i[k], Symbol[j[k - 1]]);
            if(ans == 23) return true;
        }
    }
    return false;
}

int main(){
    cin >> t;
    vector<int> ops(4);
    TryOps(ops, 0);
    while(t--){
        config.clear();
        for (int i = 0; i < 5; ++i) cin >> X[i];
        sort(X.begin(), X.end());
        config.push_back(X);
        do config.push_back(X);
        while(next_permutation(X.begin(), X.end()));
        cout << (solve() ? "YES\n" : "NO\n");
    }
}