#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n;

void TowerOfHanoi(int n, char A, char B, char C){
    if(n == 1){
        cout << A << " -> " << C << endl;
        return;
    }
    TowerOfHanoi(n - 1, A, C, B);
    cout << A << " -> " << C << endl;
    TowerOfHanoi(n - 1, B, A, C);
}

int main(){
    //cin >> t;
    while(t--){
        cin >> n;
        TowerOfHanoi(n, 'A', 'B', 'C');
    }
}