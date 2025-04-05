#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

int check(string s){
    int cnt[26]{};
    for(auto &x : s) cnt[x - 'a']++;
    for(int i = 0; i < 26; ++i) if(cnt[i] > ((s.size() >> 1) + 1) and s.size() & 1 or cnt[i] > (s.size() >> 1) and !(s.size() & 1)) return -1;
    return 1; 
}

int main(){
    boost;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << check(s) << endl;
    }
}