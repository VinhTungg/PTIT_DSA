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
    for (int i = 0; i < n; ++i)
    {
        int j = i;
        while (j > 0 && a[j] < a[j - 1])
        {
            swap(a[j], a[j - 1]);
            j--;
        }
        ans.push_back("Buoc " + to_string(i) + ": ");
        for (int j = 0; j <= i; ++j)
        {
            ans[cnt] += to_string(a[j]) + " ";
        }
        cnt++;
    }
}
int main()
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
}