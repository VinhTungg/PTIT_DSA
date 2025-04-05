/* STOLEN */

#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
vector<map<int, int>> dp;

bool check(int mid, int x, int y){
    auto it = dp[mid].lower_bound(x);
    return it != dp[mid].begin() and (--it)->second < y;
}

void Add(int l, int x, int y){
    auto it = dp[l].lower_bound(x);
    auto ori = it;
    while(it != dp[l].end() and (*it).second >= y)
        ++it;
    dp[l].erase(ori, it);
    dp[l][x] = y;
}

int main(){
    boost;
    int x, y, res = 0, l, r, mid;
    cin >> t;
    dp.resize(t);
    Add(0, INT_MIN, INT_MIN);
    while(t--){
        cin >> x >> y;
        l = 0;
        r = res;
        while(l <= r){
            mid = (l + r) >> 1;
            if(check(mid, x, y)) l = mid + 1;
            else r = mid - 1;
        }
        if(res == l - 1) res = l;
        Add(l, x, y);
    }
    cout << res;
}

/*
    Tạo một vector map để lưu tất cả các giá trị dãy con tăng dần (LIS)
    Sử dụng tìm kiếm nhị phân để tìm giá trị lớn hơn bằng x
    Sau đó check tiếp xem y có có nhỏ hơn để tạo thành dãy tăng dần hay không
*/