#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n, cnt, ans;
string s;
vector<string> v;
vector<int> a;
vector<vector<int>> b;

int Fre(string a, string b){
    int cnt = 0, p[26]{};
    for(int i = 0; i < a.size(); ++i) p[a[i] - 'A']++;
    for(int i = 0; i < b.size(); ++i) p[b[i] - 'A']++;
    for(int i = 0; i < 26; ++i) cnt += (p[i] > 1);
    return cnt;
}

int main(){
    //cin >> t;
    while(t--){
        int n; cin >> n;
        v.resize(n);
        a.resize(n);
        b.assign(n, vector<int>(30, 0));
        for(int i = 0; i < n; ++i){
            a[i] = i;
            cin >> v[i];
        }
        ans = INT_MAX;
        for(int i = 0; i < n - 1; ++i){
            for(int j = i + 1; j < n; ++j){
                int tmp = Fre(v[i], v[j]);
                b[i][j] = tmp;
                b[j][i] = tmp;
            }
        }
        do{
            cnt = 0;
            for(int i = 0; i < n - 1; ++i) cnt += b[a[i]][a[i + 1]];
            ans = min(ans, cnt);
        }while(next_permutation(a.begin(), a.end()));
        cout << ans << endl;
    }
}