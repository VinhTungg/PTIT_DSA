#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
vector<int> a;

int main(){
    boost;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        a.assign(n + 1, 0);
        for(int i = 1; i <= k; ++i) cin >> a[i];
        int pos = k;
        while(a[pos] == n - k + pos and pos) --pos;
        if(!pos){
            for(int i = 1; i <= k; ++i) cout << i << ' ';
            cout << endl;
        }else{
            a[pos]++;
            for(int i = pos + 1; i <= k; ++i){
                a[i] = a[i - 1] + 1;
            }
            for(int i = 1; i <= k; ++i) cout << a[i] << ' ';
            cout << endl;
        }
    }
}