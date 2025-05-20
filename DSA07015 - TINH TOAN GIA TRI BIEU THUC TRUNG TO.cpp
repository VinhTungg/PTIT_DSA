#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1;

int priority(char c) {
    if (c == '*' or c == '/') return 2;
    if (c == '+' or c == '-') return 1;
    return 0;
}

ll calc(ll a, ll b, char c) {
    if (c == '+') return a + b;
    if (c == '-') return a - b;
    if (c == '*') return a * b;
    return a / b;
}

int main(){
    boost;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        stack<char> ops;
        stack<ll> nums;
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                int tmp = 0;
                while (isdigit(s[i])) {
                    tmp = tmp * 10 + (s[i] - '0');
                    ++i;
                }
                --i;
                nums.push(tmp);
            } 
            else if (s[i] == '(') ops.push(s[i]);
            else if (s[i] == ')') {
                while (ops.size() and ops.top() != '(') {
                    ll b = nums.top(); nums.pop();
                    ll a = nums.top(); nums.pop();
                    char c = ops.top(); ops.pop();
                    nums.push(calc(a, b, c));
                }
                if (ops.size()) ops.pop();
            } else {
                while (ops.size() and priority(ops.top()) >= priority(s[i])) {
                    ll b = nums.top(); nums.pop();
                    ll a = nums.top(); nums.pop();
                    char c = ops.top(); ops.pop();
                    nums.push(calc(a, b, c));
                }
                ops.push(s[i]);
            }
        }
        while (ops.size()) {
            ll b = nums.top(); nums.pop();
            ll a = nums.top(); nums.pop();
            char c = ops.top(); ops.pop();
            nums.push(calc(a, b, c));
        }
        cout << nums.top() << endl;
    }
}