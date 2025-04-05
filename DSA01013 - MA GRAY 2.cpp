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

char out(char a, char b){
    if(a == '1'){
        int c = (b - '0') ^ 1;
        b = c + '0';
    }
    return b;
}

int main(){
    boost;
    int t = 1;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        string ans = "";
        ans += s[0];
        for(int i = 1; i < s.size(); ++i) ans += out(s[i], ans[i - 1]);
        cout << ans << endl;
    }
}