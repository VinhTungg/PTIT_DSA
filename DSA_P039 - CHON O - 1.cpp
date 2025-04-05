#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n;
// dp bitmask
vector<vector<int>> a;
vector<int> dp;

int Try(int row, int mask) {
    if (row == n) return 0;
    if (dp[mask] != -1) return dp[mask];
    int max_sum = INT_MIN;
    for (int col = 0; col < n; ++col) {
        if (!(mask & (1 << col))) {
            max_sum = max(max_sum, a[row][col] + Try(row + 1, mask | (1 << col)));
        }
    }
    return dp[mask] = max_sum;
}

int main() {
    boost;
    cin >> t;
    while (t--) {
        cin >> n;
        a.clear();
        a.resize(n, vector<int>(n));
        dp.clear();
        dp.resize(1 << n, -1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
        cout << Try(0, 0) << endl;
    }
    return 0;
}