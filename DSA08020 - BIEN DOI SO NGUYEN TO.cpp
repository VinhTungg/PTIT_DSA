#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1;
int isPrime[10001];

bool isprime(int n){
    for(int i = 2; i * i <= n; ++i) if(n % i == 0) return false;
    return n > 1;
}

void init(){
    for(int i = 1e3; i < 1e4; ++i)
        if(isprime(i)) isPrime[i] = 1;
}

int solve(int st, int tar){
    queue<pair<int, int>> q;
    q.push({st, 0});
    unordered_set<int> vs;
    vs.insert(st);
    while(!q.empty()){
        auto num = q.front();
        q.pop();
        if(num.first == tar) return num.second;
        string s = to_string(num.first);
        for(char &c : s){
            char tmp = c;
            for(int i = 0; i < 10; ++i){
                c = (i + '0');
                if(stoi(s) >= 1e3 and stoi(s) < 1e4 and isPrime[stoi(s)] and !vs.count(stoi(s))) {
                    q.push({stoi(s), num.second + 1});
                    vs.insert(stoi(s)); 
                }
            }
            c = tmp;
        }
    }
}

int main(){
    boost;
    cin >> t;
    init();
    while(t--){
        int st, tar;
        cin >> st >> tar;
        cout << solve(st, tar) << endl;
    }
}