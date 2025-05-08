#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int MOD = 1e9 + 7;

int64 modpow(int64 a, int64 b = MOD - 2)
{
    int64 r = 1;
    while (b)
    {
        if (b & 1)
            r = r * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return r;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int64 n;
        int K;
        cin >> n >> K;
        int m = K + 1;
        vector<int64> y(m + 1, 0);
        for (int i = 1; i <= m; i++)
        {
            y[i] = (y[i - 1] + modpow(i, K)) % MOD;
        }
        if (n <= m)
        {
            cout << y[n] << "\n";
            continue;
        }
        vector<int64> fac(m + 1, 1), ifac(m + 1, 1);
        for (int i = 1; i <= m; i++)
            fac[i] = fac[i - 1] * i % MOD;
        ifac[m] = modpow(fac[m]);
        for (int i = m; i > 0; i--)
            ifac[i - 1] = ifac[i] * i % MOD;
        vector<int64> pre(m + 1), suf(m + 1);
        pre[0] = (n % MOD);
        for (int i = 1; i <= m; i++)
            pre[i] = pre[i - 1] * ((n - i + MOD) % MOD) % MOD;
        suf[m] = ((n - m) % MOD + MOD) % MOD;
        for (int i = m - 1; i >= 0; i--)
            suf[i] = suf[i + 1] * ((n - i) % MOD + MOD) % MOD % MOD;
        int64 ans = 0;
        for (int i = 0; i <= m; i++)
        {
            int64 num = 1;
            if (i > 0)
                num = num * pre[i - 1] % MOD;
            if (i < m)
                num = num * suf[i + 1] % MOD;
            int64 den = ifac[i] * ifac[m - i] % MOD;
            if ((m - i) & 1)
                den = (MOD - den) % MOD;
            ans = (ans + y[i] * num % MOD * den) % MOD;
        }
        cout << ans << "\n";
    }
}
