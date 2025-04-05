#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

int main(){
    boost;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int ans = 0, cnt = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '['){
                ++cnt;
            }else{
                --cnt;
                if(cnt < 0){
                    for(int j = i + 1; j < s.size(); ++j){
                        if(s[j] == '['){
                            ans += j - i;
                            swap(s[i], s[j]);
                            cnt = 1;
                            break;
                        }
                    }
                }
            }
            
        }
        cout << ans << endl;
    }
}