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
        int n; cin >> n;
        if (n == 0) {
            cout << 0 << endl;
            continue;
        }
        vector<int> a(n);
        for(int &x : a) cin >> x;
        int min_arr = *min_element(a.begin(), a.end());
        int max_arr = *max_element(a.begin(), a.end());
        int cnt = 0;
        for(int i = min_arr; i <= max_arr; i++){
            if(find(a.begin(), a.end(), i) == a.end()) cnt++;
        }
        cout << cnt << endl;
    }
}