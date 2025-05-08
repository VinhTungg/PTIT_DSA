#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    boost;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n), F[3];
        int sum = 0;
        for(auto &x : a) cin >> x;
        sort(a.begin(), a.end());
        for(auto &x : a){
            sum += x;
            F[x % 3].emplace_back(x);
        }
        int remain = sum % 3;
        if(remain == 1){
            if(!F[1].empty()) F[1].erase(F[1].begin());
            else if(F[2].size() >= 2){
                F[2].erase(F[2].begin());
                F[2].erase(F[2].begin());
            }
            else{
                cout << "-1\n";
                continue;
            }
        }else if(remain == 2){
            if(!F[2].empty()) F[2].erase(F[2].begin());
            else if(F[1].size() >= 2){
                F[1].erase(F[1].begin());
                F[1].erase(F[1].begin());
            }
            else{
                cout << "-1\n";
                continue;
            }
        }
        vector<int> res;
        for(int i = 0; i < 3; ++i)
            res.insert(res.end(), F[i].begin(), F[i].end());

        if(res.empty()){
            cout << "-1\n";
            continue;
        }
        sort(res.rbegin(), res.rend());
        if(res[0] == 0) cout << "0\n";
        else {
            for(int x : res) cout << x;
            cout << '\n';
        }
    }
}
