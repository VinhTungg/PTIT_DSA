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
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        ll a[n];
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        sort(a, a + n);
        ll cnt = 0;
        for(int i = 0; i < n - 2; ++i){
            ll left = i + 1, right = n - 1;
            while(a[left] < a[right]){
                ll ans = a[i] + a[left] + a[right];
                if(ans < x){
                    cnt += right - left;
                    ++left;
                }else{
                    --right;
                }
            }
        }
        cout << cnt << "\n";
    }
}