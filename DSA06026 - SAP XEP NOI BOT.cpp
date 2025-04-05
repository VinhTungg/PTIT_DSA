#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

bool check(vector<int> &v, int n){
    for(int i = 0; i < n - 1; i++){
        if(v[i] > v[i + 1]){
            return false;
        }
    }
    return true;
}

void bubble_sort(vector<int> &v, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(v[j] > v[j + 1]){
                swap(v[j], v[j + 1]);
            }
        }
        cout << "Buoc " << i + 1 << ": ";
        for(int j = 0; j < n; j++){
            cout << v[j] << " ";
        }
        cout << endl;
        if(check(v, n)){
            break;
        }
    }
}

int main(){
    boost;
    // cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        for(auto &x : v) cin >> x;
        bubble_sort(v, n);
    }
}