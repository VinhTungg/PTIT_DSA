#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007
#define pii pair<int, int>

using namespace std;
int t = 1;
int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};

struct hash_pair{
    size_t operator()(const pii &p) const {
        return hash<ll>()(((ll)p.first << 32) | p.second);
    }
};

int BFS(pii st, pii tar, unordered_set<pii, hash_pair> &s){
    if(!s.count(st) or !s.count(tar)) return -1;
    unordered_map<pii, int, hash_pair> mp;
    queue<pii> q;
    q.push(st);
    mp[st] = 0;
    while(!q.empty()){
        pii u = q.front(); q.pop();
        if(u == tar) return mp[u];
        for(int k = 0; k < 8; ++k){
            pii v = {u.first + dx[k], u.second + dy[k]};
            if(s.count(v) and !mp.count(v)){
                mp[v] = mp[u] + 1;
                q.push(v);
            }
        }
    }
    return -1;
}

int main(){
    boost;
    cin >> t;
    while(t--){
        int xA, yA, xB, yB;
        cin >> xA >> yA >> xB >> yB;
        int n; cin >> n;
        int x, y1, y2;
        unordered_set<pii, hash_pair> s;
        for(int i = 0; i < n; ++i){
            cin >> x >> y1 >> y2;
            for(int j = y1; j <= y2; ++j){
                s.insert({x, j});
            }
        }
        int res = BFS({xA, yA}, {xB, yB}, s);
        cout << res << endl;
    }
}