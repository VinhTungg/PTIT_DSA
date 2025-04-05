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
        int k; cin >> k;
        int n = 0, m = 0;
        int limit = k / 7;
        int ok = 0, sum = 1e9;
        for(int i = 0; i <= limit; i++){
            int tmp1, tmp2;
            if((k - i * 7) % 4 == 0){
                tmp1 = (k - i * 7) / 4;
                tmp2 = i;
                if(sum > tmp1 + tmp2){
                    m = tmp1;
                    n = tmp2;
                    sum = tmp1 + tmp2;
                }
                ok = 1;
            }
        }
        if(ok){
            for(int i = 0; i < m; i++) cout << '4';
            for(int i = 0; i < n; i++) cout << '7';
            cout << endl;
        }
        else cout << -1 << endl;
    }
}