#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321

ll s,c, z, lo, hi,mid,sum;
vector<ll> v;

ll check(ll mid)
{
	ll num = 0;
	for (int i = 0; i < s; i++)
	{
		num += v[i]/mid;
	}
	return num>=c;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s >> c;
	ll ret;
	v.resize(s);
	for (int i = 0; i < s; i++)
	{
		cin >> v[i];
		sum += v[i];
	}
	lo = 1, hi = 1e9;

	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		
		if (check(mid))
		{
			ret = mid;
			lo = mid + 1;
		}
		else hi = mid - 1;
	}
	cout << sum-c*ret;
	return 0;
}
