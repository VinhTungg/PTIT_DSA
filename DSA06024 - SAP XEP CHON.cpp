#include <bits/stdc++.h>
#define ll long long
#define boost                \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
void sort(vector<int> &a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_x = a[i];
        int min_i = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < min_x)
            {
                min_x = a[j];
                min_i = j;
            }
        }
        swap(a[i], a[min_i]);
        cout << "Buoc " << i + 1 << ": ";
        for (auto x : a)
        {
            cout << x << " ";
        }
        cout << endl;
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
}