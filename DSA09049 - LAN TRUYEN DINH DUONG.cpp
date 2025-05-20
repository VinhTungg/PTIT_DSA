#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

using namespace std;

int t = 1;
vector<int> a[200005];
ll val[200005];
ll sum[200005];

void DFS(int u){
    for(int &i : a[u]){
        DFS(i);
        sum[u] += sum[i] + 1;
        val[u] += val[i];
    }
    val[u] += sum[u];
}

int main(){
    boost;
    //cin >> t;
    while (t--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i){
            a[i].clear();
            val[i] = 1;
            sum[i] = 0;
        }
        for (int i = 2; i <= n; ++i){
            int x;
            cin >> x;
            a[x].push_back(i);
        }
        DFS(1);
        for (int i = 1; i <= n; ++i){
            cout << val[i] << " ";
        }
        cout << endl;
    }
}