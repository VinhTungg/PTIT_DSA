#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1;

int main(){
    boost;
    cin >> t;
    while(t--){
        int n; cin >> n;
        unordered_set<int> visited;
        queue<pair<int, int>> q;
        q.push({n, 0});
        visited.insert(n);
        int ans = -1;
        while(!q.empty()){
            auto tmp = q.front();
            if(tmp.first == 1) {
                ans = tmp.second;
                break;
            }
            q.pop();
            int square = sqrt(tmp.first);
            for(int i = square; i >= 2; --i){
                if(tmp.first % i == 0){
                    if(!visited.count(max(i, tmp.first / i))) {
                        q.push({max(i, tmp.first / i), tmp.second + 1});
                        visited.insert(max(i, tmp.first / i));
                    }
                }
            }
            if(!visited.count(tmp.first - 1)) {
                q.push({tmp.first - 1, tmp.second + 1});
                visited.insert(tmp.first - 1);
            }
        }
        cout << ans << endl;
    }
}