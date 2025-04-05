#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

int main(){
    boost;
    cin >> t;
    while(t--){
        int n; cin >> n;
        queue<string> q;
        vector<string> res;
        q.push("6");
        q.push("8");
        while(1){
            string x = q.front();
            q.pop();
            if(x.size() > n) break;
            res.push_back(x);
            q.push(x + "6");
            q.push(x + "8");
        }
        cout << res.size() << endl;
        for(int i = res.size() - 1; i >= 0; --i) cout << res[i] << " ";
        cout << endl;
    }
}