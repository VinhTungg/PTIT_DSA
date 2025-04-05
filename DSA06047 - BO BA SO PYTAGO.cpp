#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

string check(map<ll, int> mp){
    for(auto it = mp.begin(); it != mp.end(); ++it){
        for(auto it2 = mp.begin(); it2 != mp.end(); ++it2){
            if(it2->first >= it->first){
                if(it2->first == it->first){
                    if(it2->second > 1){
                        ll x = it2->first * it2->first + it2->first * it2->first;
                        ll sqrt_x = sqrt(x);
                        if(sqrt_x * sqrt_x == x){
                            if(mp.find(sqrt_x) != mp.end()) return "YES";
                        }
                    }
                }
                else{
                    ll x = it2->first * it2->first + it->first * it->first;
                    ll sqrt_x = sqrt(x);
                    if(sqrt_x * sqrt_x == x){
                        if(mp.find(sqrt_x) != mp.end()) return "YES";
                    }
                }
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
        map<ll, int> mp;
        for(int i = 0; i < n; ++i){
            ll x; cin >> x;
            mp[x]++;
        }
        cout << check(mp) << endl;
    }
}