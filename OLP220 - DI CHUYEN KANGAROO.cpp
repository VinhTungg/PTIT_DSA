#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1;
int d[1005][1005];
int cnt[1005][1005];
struct PairHash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
    }
};

int main() {
    boost;
    cin >> t;
    while (t--) {
        int n, m, k;
        string s;
        cin >> n >> m >> k >> s;
        int len = s.size();
        vector<int> dr(len + 1, 0);
        vector<int> dc(len + 1, 0);
        for (int i = 0; i < len; ++i) {
            dr[i + 1] = dr[i];
            dc[i + 1] = dc[i];
            if (s[i] == 'U')
                --dr[i + 1];
            else if (s[i] == 'D')
                ++dr[i + 1];
            else if (s[i] == 'L')
                --dc[i + 1];
            else if (s[i] == 'R')
                ++dc[i + 1];
        }
        int mnr = 0, mxr = 0, mnc = 0, mxc = 0;
        for (int i = 0; i <= len; ++i) {
            mnr = min(mnr, dr[i]);
            mxr = max(mxr, dr[i]);
            mnc = min(mnc, dc[i]);
            mxc = max(mxc, dc[i]);
        }
        int r1 = 1 - mnr;
        int r2 = n - mxr;
        int c1 = 1 - mnc;
        int c2 = m - mxc;
        ll x_boundary_survivors = 0;
        if (r1 <= r2 && c1 <= c2) {
            x_boundary_survivors = 1LL * (r2 - r1 + 1) * (c2 - c1 + 1);
        }
        if (x_boundary_survivors == 0) {
            if (k == 0) {
                cout << 1LL * n * m << '\n';
            } else {
                cout << 0 << '\n';
            }
            continue;
        }
        if (k > x_boundary_survivors) {
            cout << 0 << '\n';
            continue;
        }
        unordered_set<ll> st_unique_displacements_keys;
        vector<pair<int, int>> v_unique_displacements;
        const ll HASH_OFFSET = 1000000LL;
        const ll HASH_MULTIPLIER = 2000000LL + 7;
        for (int i = 0; i <= len; ++i) {
            int r_disp = dr[i];
            int c_disp = dc[i];
            ll key = (r_disp + HASH_OFFSET) * HASH_MULTIPLIER + (c_disp + HASH_OFFSET);
            if (st_unique_displacements_keys.find(key) == st_unique_displacements_keys.end()) {
                st_unique_displacements_keys.insert(key);
                v_unique_displacements.push_back({r_disp, c_disp});
            }
        }
        for (int i = 0; i <= n + 1; ++i) {
            for (int j = 0; j <= m + 1; ++j) {
                d[i][j] = 0;
            }
        }
        for (const auto& p : v_unique_displacements) {
            int r_offset = p.first;
            int c_offset = p.second;
            int h_r1 = r1 + r_offset;
            int h_r2 = r2 + r_offset;
            int h_c1 = c1 + c_offset;
            int h_c2 = c2 + c_offset;
            h_r1 = max(1, h_r1);
            h_r2 = min(n, h_r2);
            h_c1 = max(1, h_c1);
            h_c2 = min(m, h_c2);
            if (h_r1 <= h_r2 && h_c1 <= h_c2) {
                d[h_r1][h_c1]++;
                d[h_r1][h_c2 + 1]--;
                d[h_r2 + 1][h_c1]--;
                d[h_r2 + 1][h_c2 + 1]++;
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                d[i][j] += d[i-1][j] + d[i][j-1] - d[i-1][j-1];
                cnt[i][j] = d[i][j];
            }
        }
        ll target_eliminated_count = x_boundary_survivors - k;
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (cnt[i][j] == target_eliminated_count) {
                    ++ans;
                }
            }
        }
        cout << ans << endl;
    }
}