#include <bits/stdc++.h>
#define ll long long
#define boost                \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
vector<string> ans;

void sort(vector<int> &a, int n)
{
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                swap(a[i], a[j]);
            }
        }
        ans.push_back("Buoc " + to_string(i + 1) + ": ");
        for (auto x : a)
        {
            ans[cnt] += to_string(x) + " ";
        }
        cnt++;
    }
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v, n);
        for(auto x = ans.rbegin(); x != ans.rend(); x++)
        {
            cout << *x << endl;
        }
        ans.clear();
    }
}