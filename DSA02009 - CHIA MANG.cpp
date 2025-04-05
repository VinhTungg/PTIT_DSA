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
vector<string> v;
vector<int> a;
vector<bool> used;
int n, k, sum = 0, ans = 0;

bool Try(int i, int cur_sum, int cnt){
    if(cnt == k - 1) return true;
    if (cur_sum == sum) return Try(0, 0, cnt + 1);
    for(int j = i; j <= n; ++j){
        if(!used[j] && cur_sum + a[j] <= sum){
            used[j] = true;
            if(Try(j + 1, cur_sum + a[j], cnt)) return true;
            used[j] = false;
        }
    }
    return false;
}

int main(){
    boost;
    int t = 1;
    cin >> t;
    while(t--){
        cin >> n >> k;
        a.resize(n);
        sum = 0;     
        for(auto &x : a){
            cin >> x;
            sum += x;
        }
        if(sum % k != 0){
            cout << "0\n";
            continue;
        }
        sum /= k;
        sort(a.rbegin(), a.rend());  // Sắp xếp giảm dần để cắt nhánh nhanh hơn
        used.assign(n, false);
        cout << Try(0, 0, 0) << endl;
    }
}