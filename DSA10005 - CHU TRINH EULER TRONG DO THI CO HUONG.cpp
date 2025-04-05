#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
vector<vector<int>> edge, reedge;

int main(){
    boost;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        edge.clear();
        reedge.clear();
        edge.resize(n + 1, vector<int>());
        reedge.resize(n + 1, vector<int>());
        while(m--){
            int a, b;
            cin >> a >> b;
            edge[a].push_back(b);
            reedge[b].push_back(a);
        }
        int ok = 1;
        for(int i = 1; i <= n; ++i){
            if(edge[i].size() != reedge[i].size()){
                ok = 0;
                break;
            }
        }
        cout << ok << endl;
    }
}