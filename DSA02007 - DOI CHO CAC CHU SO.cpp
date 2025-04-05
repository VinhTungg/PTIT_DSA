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
string s, ans;
vector<string> v;
int a[1005] = {}, b[1005] = {};
bool used[1005];
int n, k;

void Try(int i, int swaps){
    if(!swaps) return;
    char tmp = '0';
    for(int j = i; j < s.size(); ++j) tmp = max(tmp, s[j]);
    if(tmp == s[i]) Try(i + 1, swaps);
    for(int j = i + 1; j < s.size(); ++j){
        if(s[j] == tmp){
            swap(s[i], s[j]);
            ans = max(ans, s);
            Try(i + 1, swaps - 1);
            swap(s[i], s[j]);
        }
    }
}

int main(){
    boost;
    int t = 1;
    cin >> t;
    while(t--){
        cin >> n >> s;
        ans = s;
        Try(0, n);
        cout << ans << endl;
    }
}