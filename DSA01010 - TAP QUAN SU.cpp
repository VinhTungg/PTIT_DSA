#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n, k;
vector<int> a, b;

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n >> k;
        a.resize(k + 1); b.assign(n + 1, 0);
        for(int i = 1; i <= k; ++i){
            cin >> a[i];
            b[a[i]]++;
        }
        int cnt = 0, i = k;
        while(a[i] == n + i - k and i) --i;
        if(i){
            ++a[i];
            for(int j = i + 1; j <= k; ++j){
                a[j] = a[j - 1] + 1;
            }
            for(int j = 1; j <= k; ++j) cnt += (b[a[j]] == 0);
        }else cnt = k;
        cout << cnt << endl;
    }
}