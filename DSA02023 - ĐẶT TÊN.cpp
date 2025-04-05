#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n, k;
vector<string> s;
int X[20] = {};
bool visited[20];

void Try(int i){
    for(int j = X[i - 1]; j < s.size(); ++j){
        if(!visited[j]){
            X[i] = j;
            visited[j] = 1;
            if(i == k){
                for(int z = 1; z <= k; ++z) cout << s[X[z]] << ' ';
                cout << endl;
            }
            Try(i + 1);
            visited[j] = 0;
        }
    }
}

int main(){
    //cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; ++i){
            string tmp;
            cin >> tmp;
            int d = 1;
            for(auto &x : s) if(tmp == x) d = 0;
            if(d) s.push_back(tmp);
        }
        sort(s.begin(), s.end());
        memset(visited, 0, 4);
        Try(1);
    }
}