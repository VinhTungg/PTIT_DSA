#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
string s;
ll n, k;
int t = 1;

char Divide(ll num){
    if(k <= s.size()) return s[k - 1];
    if(k > num / 2){
        k -= num / 2;
        if(k > 1) --k;
        else k = num / 2;
    }
    return Divide(num / 2);
}

int main(){
    cin >> t;
    while(t--){
        cin >> s >> k;
        n = s.size();
        while(n < k) n <<= 1;
        cout << Divide(n) << endl;
    }
}