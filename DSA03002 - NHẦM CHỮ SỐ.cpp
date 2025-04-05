#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

ll min_sum(string s1, string s2){
    for(auto &x : s1) if(x == '6') x = '5';
    for(auto &x : s2) if(x == '6') x = '5';
    return stoll(s1) + stoll(s2);
}

ll max_sum(string s1, string s2){
    for(auto &x : s1) if(x == '5') x = '6';
    for(auto &x : s2) if(x == '5') x = '6';
    return stoll(s1) + stoll(s2);
}

int main(){
    boost;
    //cin >> t;
    while(t--){
        int num1, num2;
        cin >> num1 >> num2;
        cout << min_sum(to_string(num1), to_string(num2)) << ' ' << max_sum(to_string(num1), to_string(num2));  
    }
}