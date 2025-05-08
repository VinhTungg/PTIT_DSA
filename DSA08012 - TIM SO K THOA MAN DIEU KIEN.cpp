#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1;
vector<int> v;

bool check(string &s){
    int f[6]{};
    for(int i = 0; i < s.size(); ++i)
        if(++f[s[i] - '0'] > 1) return false;
    return true;
}

void init(){
    queue<string> q;
    for(int i = 1; i <= 5; ++i) v.emplace_back(i), q.push(to_string(i));
    while(!q.empty()){
        if(stoi(q.front()) > 1e5) break;
        string s = q.front();
        q.pop();
        for(int i = 0; i < 6; ++i){
            string tmp = s + to_string(i);
            if(check(tmp)){
                q.push(tmp);
                v.push_back(stoi(tmp));
            }
        }
    }
}

int main(){
    boost;
    cin >> t;
    init();
    while(t--){
        int l, r;
        cin >> l >> r;
        int st = lower_bound(v.begin(), v.end(), l) - v.begin();
        int en = lower_bound(v.begin(), v.end(), r) - v.begin();
        if(v[en] > r) --en;
        cout << en - st + 1 << endl;
    }
}