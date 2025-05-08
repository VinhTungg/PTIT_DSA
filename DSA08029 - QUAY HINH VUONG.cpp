#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1;

int solve(vector<int> &a, vector<int> &b){
    queue<pair<vector<int>, int>> q;
    q.push({a, 0});
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        if(cur.first == b) return cur.second;
        auto cur2 = cur;
        int tmp = cur.first[0];
        cur.first[0] = cur.first[3];
        cur.first[3] = cur.first[4];
        cur.first[4] = cur.first[1];
        cur.first[1] = tmp;
        q.push({cur.first, cur.second + 1});
        tmp = cur2.first[1];
        cur2.first[1] = cur2.first[4];
        cur2.first[4] = cur2.first[5];
        cur2.first[5] = cur2.first[2];
        cur2.first[2] = tmp;
        q.push({cur2.first, cur2.second + 1});
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        vector<int> a(6), b(6);
        for(int i = 0; i < 6; ++i) cin >> a[i];
        for(int i = 0; i < 6; ++i) cin >> b[i];
        cout << solve(a, b) << endl;
    }
}