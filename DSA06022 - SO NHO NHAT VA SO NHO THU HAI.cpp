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
        vector<int> a(n);
        int min_arr1 = INT_MAX, min_arr2 = INT_MAX;
        for(auto &i : a){
            cin >> i;
            if(i < min_arr1){
                min_arr2 = min_arr1;
                min_arr1 = i;
            }else if(i < min_arr2){
                min_arr2 = i;
            }
        }
        if(min_arr1 == min_arr2) cout << -1 << endl;
        else cout << min_arr1 << " " << min_arr2 << endl;
    }
}