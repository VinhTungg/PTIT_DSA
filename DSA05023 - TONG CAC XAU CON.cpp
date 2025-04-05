#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

int main(){
    boost;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        ll ans = 0;
        for (int i = 0; i < s.size(); ++i){
            string res = "";
            for (int j = i; j < s.size(); j++){
                res += s[j];
                ans += stoll(res);
            }
        }
        cout << ans << endl;
    }
}