#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

int main(){
    boost;
    cin >> t;
    while(t--){
        int s, d;
        cin >> s >> d;
        if(d * 9 < s) cout << -1 << endl;
        else{
            int res[d];
            for(int i = d - 1; i >= 0; --i){
                if(s > 9){
                    res[i] = 9;
                    s -= 9;
                }else{
                    res[i] = s;
                    s = 0;
                }
            }
            if(res[0] == 0){
                res[0] = 1;
                for(int i = 1; i < d; ++i){
                    if(res[i] != 0){
                        --res[i];
                        break;
                    }
                }
            }
            for(auto x : res) cout << x;
            cout << endl;
        }
    }
}