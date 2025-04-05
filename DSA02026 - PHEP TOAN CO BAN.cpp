#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
string s, num1, num2, num3;
char sym;
vector<int> v;
vector<string> ans;

bool calc(int num1, int num2, int num3, char sym){
    if(sym == '+') return num1 + num2 == num3;
    else return num1 - num2 == num3;
}

void Try(int i){
    if(ans.size()) return;
    for(int j = 0; j <= 9; ++j){
        v[i - 1] = j;
        if(i == (int)v.size()){
            int idx = 0, check = 1;
            string tmp1 = num1, tmp2 = num2, tmp3 = num3;
            for(int pos = 0; pos < 2; ++pos){
                if(num1[pos] == '?') {
                    if((pos == 0 && v[idx] != 0) || pos == 1) tmp1[pos] = v[idx++] + '0';
                    else check = 0;
                }
            }
            for(int pos = 0; pos < 2; ++pos){
                if(num2[pos] == '?') {
                    if((pos == 0 && v[idx] != 0) || pos == 1) tmp2[pos] = v[idx++] + '0';
                    else check = 0;
                }
            }
            for(int pos = 0; pos < 2; ++pos){
                if(num3[pos] == '?') {
                    if((pos == 0 && v[idx] != 0) || pos == 1) tmp3[pos] = v[idx++] + '0';
                    else check = 0;
                }
            }
            string tmp;
            if(sym == '?'){
                if(check){
                    if(calc(stoi(tmp1), stoi(tmp2), stoi(tmp3), '+')){
                        tmp = tmp1 + " + " + tmp2 + " = " + tmp3;
                        ans.push_back(tmp);
                    }
                    if(calc(stoi(tmp1), stoi(tmp2), stoi(tmp3), '-')){
                        tmp = tmp1 + " - " + tmp2 + " = " + tmp3;
                        ans.push_back(tmp);
                    }
                }
            }
            else {
                if(check){
                    if(calc(stoi(tmp1), stoi(tmp2), stoi(tmp3), sym)) {
                        tmp = tmp1 + " " + sym + " " + tmp2 + " = " + tmp3;
                        ans.push_back(tmp);
                    }
                }
            }
        }
        else if(i < (int)v.size()){
            Try(i + 1);
        }
    }
}

int main(){
    boost;
    cin >> t;
    cin.ignore();
    while(t--){
        v.clear();
        ans.clear();
        getline(cin, s);
        num1 = s.substr(0, 2);
        sym = s[3];
        num2 = s.substr(5, 2);
        num3 = s.substr(10, 2);
        if(sym == '*' || sym == '/'){
            cout << "WRONG PROBLEM!\n";
        }
        else{
            v.clear();
            for(int i = 0; i < 2; ++i){
                if(num1[i] == '?') v.push_back(0);
            }
            for(int i = 0; i < 2; ++i){
                if(num2[i] == '?') v.push_back(0);
            }
            for(int i = 0; i < 2; ++i){
                if(num3[i] == '?') v.push_back(0);
            }
            if(v.empty()) {
                bool valid = false;
                string tmp;
                if(sym == '?') {
                    if(calc(stoi(num1), stoi(num2), stoi(num3), '+')) {
                        tmp = num1 + " + " + num2 + " = " + num3;
                        valid = true;
                    }
                    if(calc(stoi(num1), stoi(num2), stoi(num3), '-')) {
                        tmp = num1 + " - " + num2 + " = " + num3;
                        valid = true;
                    }
                }
                else {
                    if(calc(stoi(num1), stoi(num2), stoi(num3), sym)) {
                        tmp = num1 + " " + sym + " " + num2 + " = " + num3;
                        valid = true;
                    }
                }
                if(valid) cout << tmp << endl;
                else cout << "WRONG PROBLEM!\n";
            }
            else {
                Try(1);
                if(ans.empty()) cout << "WRONG PROBLEM!\n";
                else cout << ans[0] << endl;
            }
        }
    }
}