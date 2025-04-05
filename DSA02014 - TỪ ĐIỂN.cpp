#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int k, n, m;
vector<vector<int>> used(4, vector<int>(4, 0));
vector<string> ans;
unordered_set<string> us;
vector<vector<string>> a;

void DFS(int i, int j, string s){
    if(us.find(s) != us.end()) ans.push_back(s);
    for(int z = 0; z < 8; ++z){
        int i1 = i + dx[z], j1 = j + dy[z];
        if(i1 >= 0 and i1 < m and j1 >= 0 and j1 < n and !used[i1][j1]){
            used[i1][j1] = 1;
            DFS(i1, j1, s + a[i1][j1]);
            used[i1][j1] = 0;
        }
    }
}

int main(){
    boost;
    int t = 1;
    cin >> t;
    while(t--){
        cin >> k >> m >> n;
        us.clear();
        ans.clear();
        while(k--){
            string tmp;
            cin >> tmp;
            us.insert(tmp);
        }
        a.resize(m, vector<string> (n));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j) cin >> a[i][j];
        }
        for(int i = 0; i < m; ++i){
            used[i].clear();
            for(int j = 0; j < n; ++j){
                used[i][j] = 1;
                DFS(i, j, "" + a[i][j]);
                used[i][j] = 0;
            }
        }
        if(ans.empty()) cout << "-1\n";
        else {
            for(auto &s : ans) cout << s << ' ';
            cout << endl;
        }
    }
}