#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n;
char alpha;

void Try(int i, string s = ""){
    for(int j = i; j <= alpha - 'A' + 1; ++j){
        s += (j + 'A' - 1);
        if(s.size() == n) cout << s << endl;
        else if(s.size() < n) Try(j, s);
        s.pop_back();
    }
}

int main(){
    boost;
    //cin >> t;
    while(t--){
        cin >> alpha >> n;
        Try(1);
    }
}