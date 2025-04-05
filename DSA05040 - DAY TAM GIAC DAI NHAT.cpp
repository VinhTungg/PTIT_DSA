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
        vector<int> a(n + 1), dp1(n + 1, 1), dp2(n + 1, 1);
        for(int i = 1; i <= n; ++i) cin >> a[i];
        int res = 0;
        for(int i = 2; i <= n; ++i){
            if(a[i] > a[i - 1]) dp1[i] = dp1[i - 1] + 1;
        }
        for(int i = n - 1; i; --i){
            if(a[i] > a[i + 1]) dp2[i] = dp2[i + 1] + 1;
        }
        for(int i = 1; i <= n; ++i) res = max(res, dp1[i] + dp2[i] - 1);
        cout << res << endl;
    }
}

/*
    Tìm dãy con tăng dài nhất theo chiều xuôi và chiều ngược rồi cộng lại với nhau
*/