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
string s;
int a[1005] = {}, sign[1005] = {};
int n, k;

int sinh(){
    int cnt = 0;
    int i = k;
    while(i > 0 && a[i] == n - k + i) --i;
    if(i == 0) return k;
    ++a[i];
    for(int j = i + 1; j <= k; ++j) a[j] = a[j - 1] + 1;
    for(int j = 1; j <= k; ++j) if(!sign[a[j]]) ++cnt;
    return cnt;
}

int main(){
    boost;
    int t = 1;
    cin >> t;
    while(t--){
        cin >> n >> k;
        memset(sign, 0, sizeof(sign));
        for(int i = 1; i <= k; ++i) cin >> a[i];
        for(int i = 1; i <= k; ++i) sign[a[i]] = 1;
        cout << sinh() << endl;
    }
}