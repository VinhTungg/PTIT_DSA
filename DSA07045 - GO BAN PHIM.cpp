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
    // cin >> t;
    while(t--){
        string s; cin >> s;
        stack<char> st1, st2;
        for (char &c : s) {
            if (c == '<') {
                if (st1.size()) {
                    st2.push(st1.top());
                    st1.pop();
                }
            } 
            else if (c == '>') {
                if (st2.size()) {
                    st1.push(st2.top());
                    st2.pop();
                }
            } else if (c == '-') {
                if (st1.size()) st1.pop();
            } else st1.push(c);
        } 
        while (st1.size()) {
            st2.push(st1.top()); 
            st1.pop();
        }
        while (st2.size()) {
            cout << st2.top(); 
            st2.pop();
        }
    }
}