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
        string s;
        cin >> s;
        int n = s.size();
        stack<int> st;
        vector<pair<int, int>> vp;
        for(int i = 0; i < n; ++i){
            if(s[i] == '('){
                st.push(i);
            }else if(s[i] == ')'){
                vp.push_back({st.top(), i});
                st.pop();
            }
        }
        n = vp.size();
        vector<string> res;
        for(int i = 1; i < (1ll << n); ++i){
            for(int j = 0; j < n; ++j){
                if(i & (1ll << j)){
                    s[vp[j].first] = ' ';
                    s[vp[j].second] = ' ';
                }
            }
            string tmp = "";
            for(auto &x : s){
                if(x != ' ') tmp += x;
            }
            res.push_back(tmp);
            for(int j = 0; j < n; ++j){
                if(i & (1ll << j)){
                    s[vp[j].first] = '(';
                    s[vp[j].second] = ')';
                }
            }
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        for(auto &x : res) cout << x << endl;
    }
}