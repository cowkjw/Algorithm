#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321

ll n, m, z, lo, hi,mid;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;

	z = (m * 100 / n);
	lo = 1,hi = 1000000001;

	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		int tmp = ((m + mid) * 100) / (n + mid);
		if (tmp > z)
		{
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	if (1000000001 < lo) cout << -1;
	else cout << lo;
	return 0;
}
