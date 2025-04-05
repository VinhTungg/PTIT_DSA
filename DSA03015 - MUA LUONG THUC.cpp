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
        int n, s, m;
        cin >> n >> s >> m;
        int date = s * m;
        int restDay = s - s / 7;
        int sum = restDay * n;
        if(sum < date) cout << "-1\n";
        else cout << (date + n - 1) / n << endl;
    }
}