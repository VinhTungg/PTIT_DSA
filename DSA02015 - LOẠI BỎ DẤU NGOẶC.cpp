#include<bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;

bool checkPatern(string &s){
    int cnt = 0;
    for(char &c : s){
        if(c == '(') ++cnt;
        else if(c == ')') --cnt;
        if(cnt < 0) return false;
    }
    return cnt == 0 and s.size() > 1;
}

int main(){
    boost;
    int t = 1;
    cin >> t;
    while(t--){
        set<string> ans;
        string s;
        cin >> s;
        unordered_set<string> m;
        m.insert(s);
        queue<string> q;
        q.push(s);
        bool check = 0;
        while(!q.empty()){
            string tmp = q.front();
            q.pop();
            if(checkPatern(tmp)){
                ans.insert(tmp);
                check = 1;
            }
            if(check) continue;
            for(int i = 0; i < tmp.size(); ++i){
                if(isalpha(tmp[i])) continue;
                string sub = tmp.substr(0, i) + tmp.substr(i + 1);
                if(!m.count(sub)){
                    m.insert(sub);
                    q.push(sub);
                }
            }
        }
        if(!check) cout << "-1";
        else for(auto &x : ans) cout << x << ' ';
        cout << endl;
    }
}
