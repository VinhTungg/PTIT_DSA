#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
vector<int> square;

void init(){
    for(int i = 1e2; i; --i) square.push_back(i * i * i);
}

string check(string s){
    for(auto &x : square){
        string tmp = to_string(x);
        int idx = 0;
        for(auto &i : s) if(i == tmp[idx]) ++idx;
        if(idx == tmp.size()) return tmp;
    }
    return "-1";
}

int main(){
    boost;
    init();
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << check(s) << endl;
    }
}