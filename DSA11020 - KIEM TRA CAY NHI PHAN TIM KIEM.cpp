#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, n;

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> inorder;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if(find(inorder.begin(), inorder.end(), x) == inorder.end()) inorder.emplace_back(x);
        }
        cout << (is_sorted(inorder.begin(), inorder.end()) and inorder.size() == n) << endl;
    }
}