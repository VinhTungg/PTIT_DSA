#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
vector<string> day, year;
string s = "2", Cre = "02";
int a[] = {0, 1}, X[3];

void Try(string tmp = ""){
    if(tmp.size() == 3){
        year.push_back(s + tmp);
        return;
    }else if(tmp.size() < 3){
        for(int j = 0; j <= 1; ++j){
            tmp += Cre[a[j]];
            Try(tmp);
            tmp.pop_back();
        }
    }
}

int main(){
    //cin >> t;
    while(t--){
        day.push_back("02");
        day.push_back("20");
        day.push_back("22");
        Try();
        for (auto &d : day){
            for (auto &y : year) cout << d << "/02/" << y << endl;
        }
    }
}