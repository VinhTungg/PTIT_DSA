#include <bits/stdc++.h>
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define endl '\n'
#define MOD 1000000007

using namespace std;
int t = 1;

int main(){
    boost;
    cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<int> a(n), b(m);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < m; i++) cin >> b[i];
        vector<int> res(n + m - 1, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                res[i + j] += a[i] * b[j];
            }
        }
        for(int i = 0; i < n + m - 1; i++) cout << res[i] << " ";
        cout << endl;
    }
}