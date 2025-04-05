#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

string check(vector<ll> a, unordered_map<ll, int> mp, ll k){
    sort(a.begin(), a.end());
    for(int i = 0; i < a.size(); ++i){
        for(int j = i + 1; j < a.size(); ++j){
            if(mp.find(k - a[i] - a[j]) != mp.end()){
                if(k - a[i] - a[j] != a[i] and k - a[i] - a[j] != a[j]) return "YES";
                if(k - a[i] - a[j] == a[i] and mp[a[i]] > 1) return "YES";
                if(k - a[i] - a[j] == a[j] and mp[a[j]] > 1) return "YES";
            }
        }
    }
    return "NO";
}

int main(){
    boost;
    cin >> t;
    while(t--){
        int n; cin >> n;
        ll k; cin >> k;
        vector<ll> a(n);
        unordered_map<ll, int> mp;
        for(auto &i : a){
            cin >> i;
            mp[i]++;
        }
        cout << check(a, mp, k) << endl;
    }
}