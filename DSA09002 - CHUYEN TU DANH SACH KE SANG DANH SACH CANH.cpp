#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

int main(){
    boost;
    // cin >> t;
    while(t--){
        int n; cin >> n;
        cin.ignore();
        vector<int> v[n + 1];
        for(int i = 1; i <= n; ++i){
            string s;
            getline(cin, s);
            stringstream ss(s);
            while(ss >> s){
                int num = stoi(s);
                if(num > i) v[i].push_back(num);
            }
        }
        for(int i = 1; i <= n; ++i){
            for(auto &x : v[i]) cout << i << ' ' << x << endl;
        }
    }
}