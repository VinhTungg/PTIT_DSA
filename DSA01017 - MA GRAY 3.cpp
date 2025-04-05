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

string solve(string s){
    string ans(1, s[0]);
    for(int i = 1; i < s.size(); ++i){
        ans += to_string((s[i] - '0') ^ (s[i - 1] - '0'));
    }
    return ans;
}

int main(){
    boost;
    int t = 1;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
}