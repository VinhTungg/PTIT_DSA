#include <bits/stdc++.h>
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define endl '\n'
#define MOD 1000000007

using namespace std;
int t = 1;

int main()
{
    boost;
    int n; cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        ++mp[a];
        --mp[b + 1];
    }
    map<int, int> ans;
    int tmp = 0;
    for(auto &x : mp)
    {
        tmp += x.second;
        ans[x.first] = tmp;
    }
    int q; cin >> q;
    while(q--)
    {
        int a; cin >> a;
        auto it = ans.upper_bound(a);
        if(it == ans.end()) cout << 0 << endl;
        else
        {
            --it;
            cout << it->second << endl;
        }
    }
}
