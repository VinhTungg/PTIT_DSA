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
    deque<int> dq;
    string s;
    while(t--){
        cin >> s;
        if(s == "PUSHFRONT"){
            int x;
            cin >> x;
            dq.push_front(x);
        }else if(s == "PUSHBACK"){
            int x;
            cin >> x;
            dq.push_back(x);
        }else if(s == "POPFRONT"){
            if(!dq.empty()){
                dq.pop_front();
            }
        }else if(s == "POPBACK"){
            if(!dq.empty()){
                dq.pop_back();
            }
        }else if(s == "PRINTFRONT"){
            if(!dq.empty()){
                cout << dq.front() << endl;
            }else{
                cout << "NONE" << endl;
            }
        }else{
            if(!dq.empty()){
                cout << dq.back() << endl;
            }else{
                cout << "NONE" << endl;
            }
        }
    }
}