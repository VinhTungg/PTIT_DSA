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
int a[1005] = {};
bool used[1005];
int n, k;

void Try(int i){
    for(int j = 0; j < n; ++j){
        if(!used[j]){
            used[j] = true;
            a[i] = j;
            if(i == n - 1){
                for(int z = 0; z < n; ++z) cout << v[a[z]] << ' ';
                cout << endl;
            }else Try(i + 1);
            used[j] = false;
        }
    }
}

int main(){
    boost;
    int t = 1;
    //cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; ++i){
            int num; cin >> num;
            v.push_back(num);
        }
        sort(all(v));
        Try(0);
    }
}