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
        vector<ll> v;
        queue<ll> q;
        q.push(6);
        q.push(8);
        ll limit = pow(10, n);
        while(!q.empty()){
            ll x = q.front(); q.pop();
            v.push_back(x);
            if(x * 10 + 6 < limit) q.push(x * 10 + 6);
            if(x * 10 + 8 < limit) q.push(x * 10 + 8);
        }
        for(int i = v.size() - 1; i >= 0; --i) cout << v[i] << " ";
        cout << endl;
    }
}