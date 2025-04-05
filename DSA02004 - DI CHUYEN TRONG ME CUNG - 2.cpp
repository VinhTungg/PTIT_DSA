#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MOD 1000000007

using namespace std;
vector<string> v;
int a[1005][1005] = {}, check[1005][1005] = {};
int n;

void Try(int i, int j, string s = ""){
    if(!a[i][j]) return;
    if(i == n && j == n){
        v.push_back(s);
        return;
    }
    check[i][j] = 1;
    if(i + 1 <= n && a[i + 1][j] && !check[i + 1][j]) // Xuống
        Try(i + 1, j, s + 'D');
    if(j - 1 >= 1 && a[i][j - 1] && !check[i][j - 1]) // Trái
        Try(i, j - 1, s + 'L');
    if(j + 1 <= n && a[i][j + 1] && !check[i][j + 1]) // Phải
        Try(i, j + 1, s + 'R');
    if(i - 1 >= 1 && a[i - 1][j] && !check[i - 1][j]) // Lên
        Try(i - 1, j, s + 'U');
    check[i][j] = 0;  // Bỏ đánh dấu khi quay lui
}

int main(){
    boost;
    int t = 1;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; ++i) 
            for (int j = 1; j <= n; ++j){
                cin >> a[i][j];
                check[i][j] = 0; // Reset check
            }
        v.clear();
        if(a[1][1] && a[n][n]) Try(1, 1);  // Kiểm tra nếu có thể tìm đường
        if(v.empty()) cout << "-1";
        else{
            for (auto &s : v) cout << s << ' ';
        }
        cout << endl;
    }
}
