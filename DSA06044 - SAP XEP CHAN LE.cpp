#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

int main(){
    boost;
    // cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n + 1), b, c;
        for(int i = 1; i <= n; ++i){
            cin >> a[i];
            if(i & 1) b.push_back(a[i]);
            else c.push_back(a[i]);
        }
        sort(b.begin(), b.end());
        sort(c.begin(), c.end(), greater<int>());
        int i = 0;
        while(i < b.size() && i < c.size()){
            cout << b[i] << " " << c[i] << " ";
            i++;
        }
        while(i < b.size()){
            cout << b[i] << " ";
            i++;
        }
        while(i < c.size()){
            cout << c[i] << " ";
            i++;
        }
    }
}