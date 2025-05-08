#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

ll calc(ll a, ll b, ll c)
{
    ll delta = sqrt(b * b - 4 * a * c);
    return (-b + delta) / (2 * a);
}

int main(){
    boost;
    //cin >> t;
    while(t--){
        ll x, y, z;
        cin >> x >> y >> z;
        ll sum = 1 + x * (x - 1) / 2;
        sum += ((x << 1) + y) * (y - 1) / 2;
        cout << sum << endl;
        for (int x = 1; x <= 1e6; ++x)
        {
            ll a = 1, b = (x << 1) - 1, c = x * x - 3 * x + 2 - (z << 1);
            ll tmp = calc(a, b, c);
            ll sum1 = 1 + x * (x - 1) / 2;
            sum1 += ((x << 1) + tmp) * (tmp - 1) / 2;
            if (sum1 == z)
            {
                cout << x << " " << tmp << endl;
                break;
            }
        }
    }
}