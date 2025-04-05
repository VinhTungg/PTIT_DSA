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
        int n, m;
        queue<int> q;
        cin >> m;
        while(m--){
            cin >> n;
            switch(n){
                case 1:
                    cout << q.size() << endl;
                    break;
                case 2:
                    if(q.empty()){
                        cout << "YES" << endl;
                    }else{
                        cout << "NO" << endl;
                    }
                    break;
                case 3:
                    int x;
                    cin >> x;
                    q.push(x);
                    break;
                case 4:
                    if(!q.empty()){
                        q.pop();
                    }
                    break;
                case 5:
                    if(!q.empty()){
                        cout << q.front() << endl;
                    }else{
                        cout << -1 << endl;
                    }
                    break;
                case 6: 
                    if(!q.empty()){
                        cout << q.back() << endl;
                    }else{
                        cout << -1 << endl;
                    }
                    break;
            }
        }
    }
}