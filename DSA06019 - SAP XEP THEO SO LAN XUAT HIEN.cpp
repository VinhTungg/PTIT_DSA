#include <bits/stdc++.h>
#define ll long long
#define boost                \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second != b.second ? a.second > b.second : a.first < b.first;
}

void test(){
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    vector<pair<int, int>> v(mp.begin(), mp.end());
    sort(v.begin(), v.end(), cmp);
    for (auto it : v){
        for (int i = 0; i < it.second; i++){
            cout << it.first << " ";
        }
    }
    cout << endl;
}
int main(){
    cin >> t;
    while(t--){
        test();
    }
}