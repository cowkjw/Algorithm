#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321
vector<double> v;
int n;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		double a;
		cin >> a;
		v.push_back(a);
	}
	double ret = v[0];
	double pre = v[0];
	for (int i = 1; i < n; i++)
	{
		pre = max(v[i], pre * v[i]);
		ret = max(ret, pre);
	}

	cout << fixed;
	cout.precision(3);
	cout << ret;

	return 0;
}
