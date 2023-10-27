#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321

vector<int> v;
int n, m, sum, lo, hi, mx,mid;
bool check(int mid)
{
	int tmp = mid;
	int cnt = 1;
	for (int i = 0; i < n; i++)
	{
		if (mid - v[i] < 0)
		{
			mid = tmp;
			cnt++;
		}
		mid -= v[i];
	}

	return cnt<=m;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;

	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		mx = max(mx, v[i]);
		sum += v[i];
	}
	lo = mx;
	hi = sum;
	int k = 0;

	while (lo <= hi)
	{
		mid = (lo + hi) / 2; // 금액

		if (check(mid))
		{
			k = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;

	}
	cout << k;

	return 0;
}
