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
    while(t--){
        int n; cin >> n;
        vector<int> a(n), Lmax(n + 1), Rmin(n + 1), res;
        for(auto &x : a) cin >> x;
        Lmax[0] = a[0];
        for(int i = 1; i < n; ++i) Lmax[i] = max(Lmax[i - 1], a[i]);
        Rmin[n - 1] = a[n - 1];
        for(int i = n - 2; ~i; --i) Rmin[i] = min(Rmin[i + 1], a[i]);
        for(int i = 0; i < n - 1; ++i){
            if(Lmax[i] <= Rmin[i + 1]) res.push_back(i + 1);
        }
        cout << res.size() << endl;
        for(auto &x : res) cout << x << ' ';
        cout << endl;
    }   
}

/*
Tính mảng Lmax với Lmax[i] là giá trị lớn nhất từ a[1] đến a[i].
Tính mảng Rmin với Rmin[i] là giá trị nhỏ nhất từ a[i] đến a[n].
Với mỗi chỉ số m từ 1 đến n - 1, nếu Lmax[m] ≤ Rmin[m + 1] thì chỉ số đó thỏa mãn, vì sau khi sắp xếp hai đoạn riêng biệt, 
phần cuối của đoạn trái sẽ không vượt quá phần đầu của đoạn phải, nên toàn bộ mảng sau khi ghép sẽ tăng dần.
*/