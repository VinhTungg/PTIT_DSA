#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1;
int vertex, edge, st;
vector<vector<pair<int, int>>> adj;
vector<int> dist;

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> vertex >> edge >> st;
        adj.resize(vertex + 1);
        for(int i = 1; i <= vertex; ++i) adj[i].clear();
        dist.assign(vertex + 1, INT_MAX);
        for(int i = 0; i < edge; ++i){
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        dist[st] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, st});
        while(!pq.empty()){
            auto [dis, u] = pq.top();
            pq.pop();
            if(dis <= dist[u]){
                for(auto &x : adj[u]){
                    int v = x.first;
                    int w = x.second;
                    if(dist[v] > dist[u] + w){
                        dist[v] = dist[u] + w;
                        pq.push({dist[v], v});
                    }
                }
            }
        }
        for(int i = 1; i <= vertex; ++i){
            cout << dist[i] << ' ';
        }
        cout << endl;
    }
}