#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

int main(){
    boost;
    cin >> t;
    while(t--){
        int V, E;
        cin >> V >> E;
        vector<vector<int>> a(V + 1);
        for(int i = 1; i <= E; ++i){
            int u, v; cin >> u >> v;
            a[u].push_back(v);
        }
        for(int i = 1; i <= V; ++i){
            cout << i << ": ";
            for(auto &x : a[i]) cout << x << ' ';
            cout << endl;
        }
    }
}