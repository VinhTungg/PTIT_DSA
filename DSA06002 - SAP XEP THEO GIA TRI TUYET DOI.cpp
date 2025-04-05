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
        int n, X;
        cin >> n >> X;
        vector<int> a(n);
        for(int &x : a) cin >> x;
        stable_sort(a.begin(), a.end(), [&](int x, int y){
            return abs(x - X) < abs(y - X);
        });
        for(int &x : a) cout << x << ' ';
        cout << endl;
    }
}