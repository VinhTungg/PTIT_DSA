#include <bits/stdc++.h>
#define ll long long
#define foru(i,a,b) for(int i = a; i <= b; ++i)
#define ford(i,a,b) for(int i = a; i >= b; --i)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define endl "\n"
#define sz size
#define all(a) a.begin(), a.end()
#define MOD 1000000007

using namespace std;
vector<int> v;
int a[1005][1005] = {};
vector<int> b;
vector<vector<int>> ans;
bool used[1005];
int n, k;

void Try(int i){
    for(int j = 1; j <= n; ++j){
        if(!used[j]){
            used[j] = true;
            b.push_back(j);
            if(i == n){
                int sum = 0;
                for(int z = 1; z <= n; ++z){
                    sum += a[z][b[z - 1]];
                }
                if(sum == k) ans.push_back(b);
            }else Try(i + 1);
            used[j] = false;
            b.pop_back();
        }
    }
}

int main(){
    boost;
    int t = 1;
    //cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                cin >> a[i][j];
            }
        }
        Try(1);
        cout << ans.size() << endl;
        for(auto &x : ans){
            for(auto &num : x) cout << num << ' ';
            cout << endl;
        }
    }
}