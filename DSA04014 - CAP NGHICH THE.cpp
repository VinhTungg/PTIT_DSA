#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
// Dùng merge để làm với độ phức tạp O(n)log(n)

ll MergeAndCount(vector<ll> &arr, ll left, ll mid, ll right){
    vector<ll> Vleft(arr.begin() + left, arr.begin() + mid + 1);
    vector<ll> Vright(arr.begin() + mid + 1, arr.begin() + right + 1);
    ll i = 0, j = 0, inCount = 0, k = left;
    while(i < Vleft.size() and j < Vright.size()){
        if(Vleft[i] <= Vright[j]){
            arr[k++] = Vleft[i++];
        }else{
            arr[k++] = Vright[j++];
            inCount += Vleft.size() - i;
        }
    }
    while(i < Vleft.size()) arr[k++] = Vleft[i++];
    while(j < Vright.size()) arr[k++] = Vright[j++];
    return inCount;
}

ll Count(vector<ll> &arr, ll left, ll right){
    if(left >= right) return 0;
    ll mid = (left + right) >> 1;
    ll inCount = 0;
    inCount += Count(arr, left, mid);
    inCount += Count(arr, mid + 1, right);
    inCount += MergeAndCount(arr, left, mid, right);
    return inCount;
}

int main(){
    boost;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> a(n);
        for(auto &x : a) cin >> x;
        cout << Count(a, 0, n - 1) << endl;
    }
}