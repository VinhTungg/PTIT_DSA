#include <bits/stdc++.h>
#define ll long long
#define foru(i,a,b) for(int i = a; i <= b; ++i)
#define ford(i,a,b) for(int i = a; i >= b; --i)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define endl "\n"
#define sz size
#define all(a) a.begin(), a.end()
#define MOD 1000000007

using namespace std;

int n, m;

int maxHist(int a[], int Col){
    stack<int> res;
    int top_val;
    int max_area = 0;
    int area = 0;
    int i = 0;
    while(i < Col){
        if(res.empty() || a[res.top()] <= a[i]){
            res.push(i++);
        }
        else{
            top_val = a[res.top()];
            res.pop();
            area = top_val * i;
            if(!res.empty()){
                area = top_val * (i - res.top() - 1);
            }
            max_area = max(max_area, area);
        }
    }
    while(!res.empty()){
        top_val = a[res.top()];
        res.pop();
        area = top_val * i;
        if(!res.empty()){
            area = top_val * (i - res.top() - 1);
        }
        max_area = max(max_area, area);
    }
    return max_area;
}

int maxRectangle(int a[][505]){
    int res = maxHist(a[0], m);
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(a[i][j]){
                a[i][j] += a[i - 1][j];
            }
        }
        res = max(res, maxHist(a[i], m));
    }
    return res;
}

int main(){
    boost;
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        int a[505][505];
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j) cin >> a[i][j];
        }
        cout << maxRectangle(a) << endl;
    }
}