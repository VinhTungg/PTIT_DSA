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
        string s;
        cin >> s;
        int count_X = count(s.begin(), s.end(), 'X');
        int count_D = count(s.begin(), s.end(), 'D');
        int count_T = n - count_X - count_D;
        int swapX = 0, swapD = 0, swapT = 0;
        for(int i = 0; i < count_X; ++i) swapX += (s[i] != 'X');
        for(int i = count_X; i < count_X + count_T; ++i) swapT += (s[i] != 'T');
        for(int i = count_X + count_T; i < n; ++i) swapD += (s[i] != 'D');
        int ans = min(swapX, swapT) + abs(swapX - swapT) + swapD;
        cout << ans << endl;
    }
}