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
string s;
int a[1005] = {};
int n, k;

void sinh(string &s){
    int i = s.size() - 1;
    while(i > 0 && s[i] == '0'){
        --i;
    }
    int j;
    if(i > 0){
        s[i] = '0';
        j = i + 1;
    }else{
        j = i;
    }
    for(;j < s.size(); ++j) s[j] = '1';
}

int main(){
    boost;
    int t = 1;
    cin >> t;
    while(t--){
        cin >> s;
        sinh(s);
        cout << s << endl;
    }
}