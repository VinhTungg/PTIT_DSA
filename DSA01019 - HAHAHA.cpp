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
string tmp = "AH";
int a[1005] = {};
int n, k;

bool check(string s){
    if(s[s.size() - 1] != 'A') return false;
    for(int i = 0; i < s.size() - 1; ++i){
        if(s[i] == 'H' && s[i + 1] == 'H') return false;
    }
    return true;
}

void Try(int i, string s){
    for(int j = 0; j <= 1; ++j){
        s += tmp[j];
        if(i == n){
            if(check(s)) cout << s << endl;
        }else Try(i + 1, s);
        s.pop_back();
    }
}

int main(){
    boost;
    int t = 1;
    cin >> t;
    while(t--){
        cin >> n;
        string s = "H";
        Try(2, s);
    }
}