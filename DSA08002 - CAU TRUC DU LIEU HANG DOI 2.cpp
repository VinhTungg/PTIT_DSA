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
    queue<int> q;
    while(t--){
        string s;
        cin >> s;
        if(s == "PUSH"){
            int x;
            cin >> x;
            q.push(x);
        }else if(s == "POP"){
            if(!q.empty()){
                q.pop();
            }
        }else{
            if(!q.empty()){
                cout << q.front() << endl;
            }else{
                cout << "NONE" << endl;
            }
        }
    }
}