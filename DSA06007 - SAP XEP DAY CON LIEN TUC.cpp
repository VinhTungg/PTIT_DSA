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
        int n; cin >> n;
        vector<int> a(n);
        for(int &x : a) cin >> x;
        vector<int> b = a;
        sort(b.begin(), b.end());
        int st = 0, end = 0;
        for(int i = 0; i < n; i++){
            if(a[i] != b[i]){
                st = i;
                break;
            }
        }
        for(int i = n - 1; i >= 0; i--){
            if(a[i] != b[i]){
                end = i;
                break;
            }
        }
        cout << st + 1 << ' ' << end + 1 << endl;
    }
}