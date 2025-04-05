#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

int chu[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int so[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main(){
    boost;
    cin >> t;
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;
        queue<pair<string, int>> q;
        unordered_set<string> visited;
        q.push({s1, 0});
        visited.insert(s1);
        int ans = -1;
        while(!q.empty()){
            auto tmp = q.front();
            q.pop();
            if(tmp.first == s2){
                ans = tmp.second;
                break;
            }
            for(int i = 0; i < 8; ++i){
                if(char(tmp.first[0] + chu[i]) >= 'a' and char(tmp.first[0] + chu[i]) <= 'h' and char(tmp.first[1] + so[i]) >= '1' and char(tmp.first[1] + so[i]) <= '8'){
                    char a = tmp.first[0] + chu[i], b = tmp.first[1] + so[i];
                    string new_str = string(1, a) + string(1, b);
                    if(!visited.count(new_str)) {
                        q.push({new_str, tmp.second + 1});
                        visited.insert(new_str);
                    }
                }
            }
        }
        cout << ans << endl;
    }
}