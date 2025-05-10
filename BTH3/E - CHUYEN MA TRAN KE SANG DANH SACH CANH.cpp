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
    // cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> adj[n + 1];
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                int x; cin >> x;
                if(x == 1) adj[i].push_back(j);
            }
        }
        for(int i = 1; i <= n; ++i){
            for(int j : adj[i]){
                cout << j << ' ';
            }
            cout << endl;
        }
    }
}