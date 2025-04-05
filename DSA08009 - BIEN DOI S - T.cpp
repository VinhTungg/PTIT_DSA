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
        int s, t;
        cin >> s >> t;
        queue<pair<int, int>> num;
        unordered_set<int> visited;
        num.push({s, 0});
        visited.insert(s);
        int ans = -1;
        while(!num.empty()){
            auto tmp = num.front();
            num.pop();
            if(tmp.first == t){
                ans = tmp.second;
                break;
            }
            if(tmp.first <= t and !visited.count(tmp.first * 2)) {
                num.push({tmp.first * 2, tmp.second + 1});
                visited.insert(tmp.first * 2);
            }
            if(tmp.first - 1 > 0 and !visited.count(tmp.first - 1)){
                num.push({tmp.first - 1, tmp.second + 1});
                visited.insert(tmp.first - 1);
            }
        }
        cout << ans << endl;
    }
}