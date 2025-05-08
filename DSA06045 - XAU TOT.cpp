#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

int main(){
    boost;
    //cin >> t;
    while(t--){
        int n; string s;
        cin >> n >> s;
        ll len = (1ll * n * (n - 1)) >> 1;
        vector<int> v;
        int cnt = 1;
        for(int i = 1; i < s.size(); ++i){
            if(s[i] == s[i - 1]) ++cnt;
            else{
                v.emplace_back(cnt);
                cnt = 1;
            }
        }
        v.emplace_back(cnt);
        for(int i = 1; i < v.size(); ++i){
            len -= (v[i] + v[i - 1] - 1);
        }
        cout << len << endl;
    }
}