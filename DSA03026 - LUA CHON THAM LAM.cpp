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
        int n, s;
        cin >> n >> s;
        if(s == 0){
            if (n == 1) cout << "0 0" << endl;
            else cout << "-1 -1" << endl;
            continue;
        }
        if(s < 1 || s > 9 * n){
            cout << "-1 -1" << endl;
            continue;
        }
        string smallest_num_str = "";
        vector<int> min_digits(n);
        int tempS_min = s;
        tempS_min--;
        for(int i = n - 1; i > 0; --i) {
            int d = min(9, tempS_min);
            min_digits[i] = d;
            tempS_min -= d;
        }
        min_digits[0] = tempS_min + 1;
        for(int digit : min_digits) {
            smallest_num_str += to_string(digit);
        }
        string largest_num_str = "";
        int tempS_max = s;
        for(int i = 0; i < n; ++i) {
            int d = min(9, tempS_max);
            largest_num_str += to_string(d);
            tempS_max -= d;
        }
        cout << smallest_num_str << " " << largest_num_str << endl;
    }
}