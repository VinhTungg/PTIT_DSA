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
        int n, k; cin >> n >> k;
        vector<int> v(n);
        for(auto &x : v) cin >> x;
        int min_num = 0, max_num = 0;
        if(k > n / 2){
            sort(v.begin(), v.end(), greater<int>());
        }
        else{
            sort(v.begin(), v.end());
        }
        for(int i = 0; i < v.size(); ++i){
            if(i < k) min_num += v[i];
            else max_num += v[i];
        }    
        cout << abs(max_num - min_num) << endl;
    }
}