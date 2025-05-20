#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        ll N, M, K;
        cin >> N >> M >> K;
        string S;
        cin >> S;

        // Theo dõi dịch chuyển dọc (dx) và ngang (dy)
        ll dx = 0, dy = 0;
        ll min_dx = 0, max_dx = 0;
        ll min_dy = 0, max_dy = 0;

        for (char c : S) {
            if (c == 'U') --dx;
            else if (c == 'D') ++dx;
            else if (c == 'L') --dy;
            else if (c == 'R') ++dy;
            min_dx = min(min_dx, dx);
            max_dx = max(max_dx, dx);
            min_dy = min(min_dy, dy);
            max_dy = max(max_dy, dy);
        }

        // Xác định vùng an toàn của hàng và cột
        ll row_low  = max(0LL, -min_dx);
        ll row_high = min(N-1, N-1 - max_dx);
        ll col_low  = max(0LL, -min_dy);
        ll col_high = min(M-1, M-1 - max_dy);

        ll safe_rows = row_high >= row_low ? row_high - row_low + 1 : 0;
        ll safe_cols = col_high >= col_low ? col_high - col_low + 1 : 0;
        ll C = safe_rows * safe_cols;      // số ô ban đầu mà kangaroo nếu có sẽ sống

        ll total = N * M;
        ll ans = 0;
        // Trường hợp C == K  -> đặt hố ngoài vùng an toàn (total - C vị trí)
        if (C == K) 
            ans += total - C;
        // Trường hợp C == K+1 -> đặt hố trong vùng an toàn (C vị trí)
        if (C == K + 1)
            ans += C;

        cout << ans << "\n";
    }
    return 0;
}
