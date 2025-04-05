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
        int k; cin >> k;
        string s; cin >> s;
        int alpha[26]{};
        for(int i = 0; i < s.size(); i++){
            alpha[s[i] - 'A']++;
        }
        priority_queue<int> pq;
        for(int i = 0; i < 26; i++){
            if(alpha[i] > 0) pq.push(alpha[i]);
        }
        while(k--){
            int x = pq.top(); pq.pop();
            x--;
            pq.push(x);
        }
        ll res = 0;
        while(!pq.empty()){
            res += pq.top() * pq.top();
            pq.pop();
        }
        cout << res << endl;
    }
}