#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
vector<vector<int>> edge;

int main(){
    boost;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        edge.clear();
        edge.resize(n + 1, vector<int>());
        while(m--){
            int a, b;
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        int ct = 0, dd = 0;
        for(int i = 1; i <= n; ++i){
            if(edge[i].size()){
                if(edge[i].size() & 1) ++dd;
                else ++ct;
            }
        }
        if(ct == n){
            cout << "2\n";
        }else if(dd == 2){
            cout << "1\n";
        }else cout << "0\n";
    }
}