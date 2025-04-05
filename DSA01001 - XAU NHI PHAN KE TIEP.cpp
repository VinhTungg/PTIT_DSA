#include <bits/stdc++.h>
#define ll long long
#define foru(i,a,b) for(int i = a; i <= b; ++i)
#define ford(i,a,b) for(int i = a; i >= b; --i)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define endl "\n"
#define sz size
#define all(a) a.begin(), a.end()
#define MOD 1000000007

using namespace std;

void sinh(string &a){
    int i = a.size() - 1;
    while(a[i] == '1' && i > 0){
        --i;
    }
    a[i] = '1';
    for(int j = i + 1; j < a.size(); ++j) a[j] = '0';
}

int main(){
    boost;
    int t = 1; 
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        s = "0" + s;
        sinh(s);
        s.erase(0, 1);
        cout << s << endl;
    }
}