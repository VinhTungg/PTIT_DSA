#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1;
int r[] = {3, 0, 2, 7, 4, 1, 6, 8, 5, 9};
int l[] = {0, 4, 1, 3, 8, 5, 2, 7, 9, 6};
int l2[] = {1, 5, 2, 0, 4, 8, 6, 3, 7, 9};
int r2[] = {0, 2, 6, 3, 1, 5, 9, 7, 4, 8};

bool check(string &s) {
    return s == "1238004765";
}

string rotate(string &s, int mp[]) {
    string t = "";
    for (int i = 0; i < 10; ++i)
        t += s[mp[i]];
    return t;
};

int BFS(string &s) {
    unordered_map<string, int> mp;
    queue<pair<string, int>> q1, q2;
    q1.push({s, 0});
    int ans = 1e9;
    while (q1.size()) {
        auto [str, fre] = q1.front();
        q1.pop();
        if (check(str)) return fre;
        // turn on the left
        pair<string, int> tmp = {rotate(str, l), fre + 1};
        if (!mp[tmp.first]) {
            q1.push(tmp);
            mp[tmp.first] = tmp.second;
        }
        // turn on the right
        tmp.first = rotate(str, r);
        if (!mp[tmp.first]) {
            q1.push(tmp);
            mp[tmp.first] = tmp.second;
        }
        if (fre == 14) break;
    }
    string t = "1238004765";
    q2.push({t, 0});
    while (q2.size()) {
        auto [str, fre] = q2.front();
        q2.pop();
        if (mp[str]) {
            // cerr << str << ' ' << mp[str] << ' ' << fre << endl;
            ans = min(ans, mp[str] + fre);
        }
        // turn on the left
        pair<string, int> tmp = {rotate(str, l2), fre + 1};
        q2.push(tmp);
        // turn on the right
        tmp.first = rotate(str, r2);
        q2.push(tmp);
        if (fre == 14) break;
    }
    return ans;
}

int main() {
    boost;
    cin >> t;
    while (t--) {
        string s = "";
        int x;
        for (int i = 0; i < 10; ++i) cin >> x, s += to_string(x);
        cout << BFS(s) << endl;
    }
}