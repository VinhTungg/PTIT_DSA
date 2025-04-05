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
        sort(a.begin(), a.end(), greater<int>());
        vector<int> b = a;
        sort(a.begin(), a.end());
        vector<int> c = a;
        int m = 0, cnt = 0;
        while(m < n){
            cout << b[cnt] << ' ';
            ++m;
            if(m == n) break;
            cout << c[cnt] << ' ';
            ++m;
            ++cnt;
        }
        cout << endl;
    }
}