#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1;

int main(){
    boost;
    cin >> t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin, s);
        stack<string> st;
        stringstream ss(s);
        while(ss >> s){
            st.push(s);
        }
        while(!st.empty()){
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
}