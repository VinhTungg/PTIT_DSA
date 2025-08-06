#include<bits/stdc++.h>
#define boost ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);

using namespace std;
using ll = long long;

int n, m, p;

struct Matrix {
	ll x[55][55];
	friend Matrix operator * (Matrix a, Matrix b) {
		Matrix c;
		for (int i = 0; i<n; ++i) {
			for (int j = 0; j<p; ++j) {
				c.x[i][j] = 0;
				for (int k = 0; k<m; ++k) {
					c.x[i][j] += 1ll * a.x[i][k] * b.x[k][j];
				}
			}
		}
		return c;
	}
	
	friend ostream& operator << (ostream& out, Matrix &r) {
		for (int i = 0; i<n; ++i) {
			for (int j = 0; j<p; ++j) out << r.x[i][j] << ' ';
			out << '\n';
		}
		return out;
	}
};

int main()
{
	boost;
	cin >> n >> m >> p;
	Matrix a, b;
	for (int i = 0; i<n; ++i) {
		for (int j = 0; j<m; ++j) cin >> a.x[i][j];
	}
	for (int i = 0; i<m; ++i) {
		for (int j = 0; j<p; ++j) cin >> b.x[i][j];
	}
	Matrix res = a*b;
	cout << res;
	return 0;
}