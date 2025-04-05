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
int a[1005] = {};
int n, k;

int main(){
    boost;
    int t = 1;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i <= k; ++i) cin >> a[i];
        if(a[k] == k){
            for(int i = 1; i <= k; ++i){
                cout << n - k + i << ' ';
            }
        }else{
            int i = k;
            while(i > 0 && a[i] - a[i - 1] == 1){
                --i;
            }
            a[i]--;
            for(int j = i + 1; j <= k; ++j){
                a[j] = n + j - k;
            }
            for(int i = 1; i <= k; ++i){
                cout << a[i] << ' ';
            }
        }
        cout << endl;
    }
}