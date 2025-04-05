#include <bits/stdc++.h>
#define ll long long
#define boost                \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

int main(){
    boost;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            b[i] = a[i];
        }
        int cnt = 0;
        sort(b.begin(), b.end());
        for(int i = 0; i < n; i++){
            if(a[i] != b[i]){
                for(int j = i + 1; j < n; j++){
                    if(a[j] == b[i]){
                        cnt++;
                        swap(a[i], a[j]);
                        break;
                    }
                }
            }
        }
        cout << cnt << "\n";
    }
}