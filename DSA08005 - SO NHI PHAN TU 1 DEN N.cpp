#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
queue<string> q;
vector<string> v;

void init(){
    q.push("1");
    v.push_back("1");
    while(1){
        string s = q.front();
        q.pop();
        string s1 = s + "0";
        string s2 = s + "1";
        q.push(s1);
        q.push(s2);
        v.push_back(s1);
        v.push_back(s2);
        if(v.size() > 10000){
            break;
        }
    }
}

int main(){
    boost;
    cin >> t;
    init();
    while(t--){
        int n; cin >> n;
        for(int i = 0; i < n; i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
}