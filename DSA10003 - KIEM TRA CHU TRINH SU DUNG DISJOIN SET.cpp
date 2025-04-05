#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n, m;
vector<int> parent;

void init(){
    for(int i = 1; i <= n; ++i) parent[i] = i;
}

int Find(int u){
    if(u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}

bool Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if(u == v) return false;
    parent[v] = u;
    return true;
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n >> m;
        parent.resize(n + 1);
        init();
        int check = 0;
        while(m--){
            int a, b;
            cin >> a >> b;
            if(!Union(a, b)) check = 1;
        }
        cout << (check ? "YES\n" : "NO\n");
    }
}