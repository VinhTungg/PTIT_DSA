#include <bits/stdc++.h>
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define endl '\n'
#define MOD 1000000007

using namespace std;
int t = 1, k;
int a[100];
string s;
ll sum;

void calc(int i){
    ll tmp = 0;
    for(int j = k; j <= i; j++) tmp = tmp * 10 + a[j];
    sum += tmp;
}

void Try(int i){
    for(int j = i - 1; j < s.size(); ++j){
        a[i] = s[j] - '0';
        calc(i);
        Try(i + 1);
        j = s.size() - 1;
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> s;
        sum = 0;
        for(k = 1; k <= s.size(); ++k) Try(k);
        cout << sum << endl;
    }
}