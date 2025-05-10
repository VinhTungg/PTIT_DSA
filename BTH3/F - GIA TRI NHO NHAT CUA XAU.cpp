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
        int k; cin >> k;
        string s; cin >> s;
        int F[26] = {0};
        for(char x : s) F[x - 'A']++;
        priority_queue<int> pq;
        for(int i = 0; i < 26; ++i) pq.push(F[i]);
        while(k--){
            int x = pq.top(); pq.pop();
            x--;
            pq.push(x);
        }
        ll res = 0;
        while(!pq.empty()){
            int x = pq.top(); pq.pop();
            res += 1ll * x * x;
        }
        cout << res << endl;
    }
}