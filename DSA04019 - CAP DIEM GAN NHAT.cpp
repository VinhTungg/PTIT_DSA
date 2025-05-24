#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define time cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
#define endl "\n"
#define MOD 1000000007
#define pid pair<double, double>

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, n, x, y;

double dist(pid a, pid b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

double solve(vector<pid> &P_x, vector<pid> &P_y) {
    if (P_x.size() <= 3) {
        double min_dist = 1e18;
        for (int i = 0; i < P_x.size(); i++) {
            for (int j = i + 1; j < P_x.size(); j++) {
                min_dist = min(min_dist, dist(P_x[i], P_x[j]));
            }
        }
        return min_dist;
    }
    int mid = P_x.size() >> 1;
    auto mid_point = P_x[mid];
    vector<pid> P_left_x(P_x.begin(), P_x.begin() + mid);
    vector<pid> P_right_x(P_x.begin() + mid, P_x.end());
    vector<pid> P_left_y, P_right_y;
    for (auto &i : P_y) {
        if (i.first <= mid_point.first) {
            P_left_y.push_back(i);
        } else {
            P_right_y.push_back(i);
        }
    }
    double d1 = solve(P_left_x, P_left_y);
    double d2 = solve(P_right_x, P_right_y);
    double d = min(d1, d2);
    vector<pid> P_strip;
    for (auto &i : P_y) {
        if (abs(i.first - mid_point.first) < d) {
            P_strip.push_back(i);
        }
    }
    for (int i = 0; i < P_strip.size(); ++i) {
        for (int j = i + 1; j < P_strip.size() and (P_strip[j].second - P_strip[i].second) < d; ++j) {
            d = min(d, dist(P_strip[i], P_strip[j]));
        }
    }
    return d;
}

int main() {
    boost;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<pid> P(n);
        for (auto &i : P) cin >> i.first >> i.second;
        if (n < 2) {
            cout << "0\n";
            continue;
        }
        vector<pid> P_x = P, P_y = P;
        sort(P_x.begin(), P_x.end());
        sort(P_y.begin(), P_y.end(), [](pid a, pid b) {
            return a.second < b.second;
        });
        cout << fixed << setprecision(6) << solve(P_x, P_y) << endl;
    }
    time;
}