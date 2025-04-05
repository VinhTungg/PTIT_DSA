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
int n, k, s, ans;
bool used[25];
int a[25] = {};

void Try(int i, int sum, int st = 1){
    for(int j = st; j <= n; ++j){
        if(!used[j]){
            used[j] = true;
            a[i] = j;
            if(i == k){
                if(sum + a[i] == s) ++ans;
            }else if(i < k && sum + a[i] <= s) Try(i + 1, sum + a[i], j + 1);
            used[j] = false;
        }
    }
}

int main(){
    boost;
    while(cin >> n >> k >> s){
        if(!n && !k && !s) break;
        ans = 0;
        Try(1, 0);
        cout << ans << endl;
    }
}