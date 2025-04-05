#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

using namespace std;
int t = 1;

int main() {
    boost;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n;
        vector<pair<int, int>> jobs(n);
        for (auto &job : jobs) {
            cin >> x >> job.first >> job.second;
        }
        sort(jobs.begin(), jobs.end(), greater<>());
        priority_queue<int> pq;
        int maxDeadline = jobs[0].first;
        int profit = 0, count = 0, idx = 0;
        for (int date = maxDeadline; date > 0; --date){
            while (idx < n && jobs[idx].first >= date){
                pq.push(jobs[idx].second);
                ++idx;
            }
            if(!pq.empty()) {
                profit += pq.top();
                pq.pop();
                ++count;
            }
        }
        cout << count << " " << profit << endl;
    }
}
