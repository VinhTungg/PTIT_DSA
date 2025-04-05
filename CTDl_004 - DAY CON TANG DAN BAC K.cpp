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
int n, k;
int a[105];
int res = 0;

void Try(int i, int cnt){
    for(int j = i + 1; j <= n; ++j){
        if(a[j] > a[i]){
            ++cnt;
            if(cnt == k) ++res;
            else Try(j, cnt);
            --cnt;
        }
    }
}

int main(){
    boost;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    Try(0, 0);
    cout << res;
}