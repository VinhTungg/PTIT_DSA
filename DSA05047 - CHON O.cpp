#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
int ok[] = {1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0}; // mảng cấu hình cho chọn được
vector<vector<ll>> a, dp;

int Get_val(int i, int x){
    int res = 0;
    for(int j = 0; j <= 3; ++j){
        if(x & (1 << j)) res += a[j][i];
    }
    return res;
}

int main(){
    boost;
    cin >> t;
    while(t--){
        int n; cin >> n;
        a.assign(4, vector<ll>(n + 1, 0));
        dp.assign(n + 1, vector<ll>(1 << 4, -1e9));
        ll res = -1e9;
        for(int i = 0; i <= 3; ++i) for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
            res = max(res, a[i][j]);
        }
        if(res < 0){
            cout << res << endl;
            continue;
        }
        for(int i = 1; i <= n; ++i){
            for(int x = 0; x < 16; ++x){
                if(ok[x]){
                    int val = Get_val(i, x);
                    if(i == 1) dp[i][x] = val;
                    else{
                        dp[i][x] = -1e9;
                        for(int z = 0; z < 16; ++z){
                            if(ok[z] and !(x & z)){
                                dp[i][x] = max(dp[i][x], dp[i - 1][z] + val);
                            }
                        }
                    }
                }
            }
        }
        for(int i = 0; i < 16; ++i) res = max(res, dp[n][i]);
        cout << res << endl;
    }
}

/*
    Nhận thấy với 4 hàng ta sẽ có 2 ^ 4 cấu hình để chọn (0000, 0001, 0010, ...) với 1 sẽ là các ô được chọn
    0 |  |  |  |  |
    1 |  |  |  |  |
    2 |  |  |  |  |
    3 |  |  |  |  |
    Ma trận 4 x N với một cột sẽ chọn được vài cấu hình, đề bài nói rằng không có 2 ô nào được trùng cạnh
    nên sẽ có một số cấu hình không thỏa mãn (các cấu hình có 2 số một đứng cạnh nhau) vì vậy một số cấu 
    hình thỏa mãn là: 0000, 0001, 0010, 0100, 0101, 1000, 1001, 1010
    Hướng giải quyết: Ta sẽ đi duyệt tùng cột một và xem cột đó được chọn những ô nào và chúng ta sẽ tính tổng của
    dp[i - 1][x] + a[i][z]
*/