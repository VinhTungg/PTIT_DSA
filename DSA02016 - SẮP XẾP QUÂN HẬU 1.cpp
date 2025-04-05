#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n, cnt;
int X[15];
bool Cot[25], Xuoi[25], Nguoc[25];

void Try(int i){
    for(int j = 1; j <= n; ++j){
        if(!Cot[j] and !Xuoi[n + i - j] and !Nguoc[i + j - 1]){
            X[i] = j;
            Cot[j] = 1, Xuoi[n + i - j] = 1, Nguoc[i + j - 1] = 1;
            if(i == n) ++cnt;
            else Try(i + 1);
            Cot[j] = 0, Xuoi[n + i - j] = 0, Nguoc[i + j - 1] = 0;
        }
    }
}

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        cnt = 0;
        Try(1);
        cout << cnt << endl;
    }
}