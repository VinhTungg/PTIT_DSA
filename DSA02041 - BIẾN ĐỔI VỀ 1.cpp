#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n;

int BFS(int n){
    queue<int> q;
    unordered_map<int, int> steps;
    q.push(n);
    steps[n] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        int cur_step = steps[cur];
        if(cur == 1) return cur_step;
        if(cur % 2 == 0 and steps.find(cur / 2) == steps.end()){
            q.push(cur / 2);
            steps[cur / 2] = cur_step + 1;
        }
        if(cur % 3 == 0 and steps.find(cur / 3) == steps.end()){
            q.push(cur / 3);
            steps[cur / 3] = cur_step + 1;
        }
        if(steps.find(cur - 1) == steps.end()){
            q.push(cur  - 1);
            steps[cur - 1] = cur_step + 1;
        }
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n;
        cout << BFS(n) << endl;
    }
}