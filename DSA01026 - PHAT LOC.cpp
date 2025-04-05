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
string tmp = "68";
string s = "";
int a[1005] = {};
bool used[1005];
int n, k;

bool check(string s){
    int len = s.length() - 1;
    if(s[len] != '6') return false;
    int sau = 0;
    for(int i = 0; i <= len - 1; ++i){
        if(s[i] == '8' && s[i + 1] == '8') return false;
        if(s[i] == '6' && s[i + 1] == '6') ++sau;
        else sau = 0;
        if(sau == 3) return false;
    }
    return true;
}

void Try(string s){
    for(int j = 0; j <= 1; ++j){
        s += tmp[j];
        if(s.size() == n){
            if(check(s)) cout << s << endl;
        }else Try(s);
        s.pop_back();
    }
}

int main(){
    boost;
    int t = 1;
    //cin >> t;
    while(t--){
        cin >> n;
        s += '8';
        Try(s);
    }
}