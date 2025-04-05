#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
vector<ll> num;

void init(){
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    unordered_set<ll> seen;
    pq.push(1);
    seen.insert(1);
    while(num.size() <= 1e4){
        ll tmp = pq.top();
        pq.pop();
        num.push_back(tmp);
        ll next[] = {tmp * 2, tmp * 3, tmp * 5};
        for(auto val : next){
            if(seen.find(val) == seen.end()){
                pq.push(val);
                seen.insert(val);
            }
        }
    }
}

int main(){
    boost;
    cin >> t;
    init();
    while(t--){
        int n; cin >> n;
        cout << num[n - 1] << endl;
    }
}