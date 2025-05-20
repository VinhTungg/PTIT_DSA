#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1;

struct Edge {
    int u, v, w;
};

int main(){
    boost;
    cin >> t;
    while(t--){
        int v, e;
        cin >> v >> e;
        vector<Edge> Edges;
        Edges.reserve(v + e);
        for (int i = 0; i < e; ++i) {
            int x, y, z;
            cin >> x >> y >> z;
            Edges.push_back({x - 1, y - 1, z});
        }
        for (int i = 0; i < v; ++i) {
            Edges.push_back({v, i, 0});
        }
        ll INF = LLONG_MAX;
        vector<ll> dist(v + 1, INF);
        dist[v] = 0;
        for (int i = 0; i < v; ++i) {
            for (const auto &e : Edges) {
                if (dist[e.u] != INF and dist[e.u] + e.w < dist[e.v]) {
                    dist[e.v] = dist[e.u] + e.w;
                }
            }
        }
        bool isNegCycle = 0;
        for (const auto &e : Edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                isNegCycle = 1;
                break;
            }
        }
        cout << isNegCycle << endl;
    }
}