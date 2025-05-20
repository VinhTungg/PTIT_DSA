#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1;
vector<string> v;
string a, b;
unordered_set<string> had;

bool check(string s1, string s2) {
    int diff = 0;
    for (int i = 0; i < s1.size(); ++i) {
        diff += (s1[i] != s2[i]);
    }
    return diff == 1;
}

int BFS() {
    queue<pair<string, int>> q;
    q.push({a, 1});
    had.erase(a);
    while (q.size()) {
        auto [s, fre] = q.front();
        q.pop();
        if (s == b) return fre;
        string tmp = s;
        for (int i = 0; i < s.size(); ++i) {
            char c = tmp[i];
            for (char j = 'A'; j <= 'Z'; ++j){
                tmp[i] = j;
                if (!had.count(tmp)) continue;
                else {
                    if (check(s, tmp)) {
                        had.erase(tmp);
                        q.push({tmp, fre + 1});
                    }
                }
            }
            tmp[i] = c;
        }
    }
    return -1;
}

int main(){
    boost;
    cin >> t;
    while(t--){
        int n; cin >> n;
        cin >> a >> b;
        v.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            had.insert(v[i]);
        }
        cout << BFS() << endl;
    }
}