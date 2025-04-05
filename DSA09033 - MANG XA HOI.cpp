#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n, m;
vector<int> parent, sz;
unordered_set<int> s;

void init(){
    for(int i = 1; i <= n; ++i){
        parent[i] = i;
        sz[i] = 1;
    }
}

int Find(int u){
    if(u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}

void Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if(u == v) return;
    if(sz[u] < sz[v]) swap(u, v);
    parent[v] = u;
    sz[u] += sz[v];
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n >> m;
        s.clear();
        parent.assign(n + 1, 0);
        sz.assign(n + 1, 0);
        init();
        for(int i = 0; i < m; ++i){
            int a, b;
            cin >> a >> b;
            Union(a, b);
        }
        ll ans = 0;
        for(int i = 1; i <= n; ++i){
            if(!s.count(Find(i))){
                s.insert(Find(i));
                ans += 1ll * (sz[Find(i)] - 1) * sz[Find(i)] / 2;
            }
        }
        cout << (ans == m ? "YES" : "NO") << endl;
    }
}