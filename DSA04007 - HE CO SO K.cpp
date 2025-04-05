#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

int num(string a, int k){
    int res = 0;
    for(auto &i : a) res = res * k + (i - '0');
    return res;
}

int main(){
    boost;
    cin >> t;
    while(t--){
        int k;
        string a, b;
        cin >> k >> a >> b;
        int tmp = num(a, k) + num(b, k);
        string s;
        while(tmp){
            s.push_back((tmp % k) + '0');
            tmp /= k;
        }
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
}