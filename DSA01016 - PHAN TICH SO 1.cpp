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
int a[15] = {}, n;

void Try(int i, int sum, int st = n){
    for(int j = st; j >= 1; --j){
        a[i] = j;
        if(sum + a[i] == n){
            cout << "(";
            for(int z = 1; z <= i; ++z){
                if(z != i) cout << a[z] << ' ';
                else cout << a[z];
            }
            cout << ") ";
        }else if(sum + a[i] <= n) Try(i + 1, sum + a[i], j); 
    }
}

int main(){
    boost;
    int t = 1;
    cin >> t;
    while(t--){
        cin >> n;
        Try(1, 0);
        cout << endl;
    }
}