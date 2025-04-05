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

string check(string &s){
    int len = s.size() - 1, break_point = -1;
    for(int i = len - 1; i >= 0; --i){
        if(s[i] < s[i + 1]){
            break_point = i;
            break;
        }
    }
    if(break_point == -1) return "BIGGEST";
    else {
        for(int i = len; i > break_point; --i) if(s[i] > s[break_point]){
            swap(s[i], s[break_point]);
            break;
        }
        sort(s.begin() + break_point + 1, s.end());
    }
    return s;
}

int main(){
    boost;
    int t = 1;
    cin >> t;
    for(int _ = 1; _ <= t; ++_){
        int n;
        string s;
        cin >> n >> s;
        s = check(s);
        cout << _ << ' ' << s << endl;
    }
}