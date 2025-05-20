#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, idx;
vector<int> pre, post;

void build(int lo, int hi) {
    if (idx >= (int)pre.size() or pre[idx] < lo or pre[idx] > hi) return;
    int val = pre[idx++];
    build(lo, val - 1);
    build(val, hi);
    post.emplace_back(val);
}

int main(){
    boost;
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        pre.resize(n);
        for (auto &x : pre) cin >> x;
        post.clear();
        idx = 0;
        build(INT_MIN, INT_MAX);
        for (auto &x : post) cout << x << ' ';
        cout << endl;
    }
}