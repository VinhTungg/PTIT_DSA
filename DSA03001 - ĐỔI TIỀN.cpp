#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n;
int money[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n;
        int ans = 0;
        for(int i = 9; ~i; --i){
            if(n >= money[i]){
                ans += n / money[i];
                n %= money[i];
            }
        }
        cout << ans << endl;
    }
}