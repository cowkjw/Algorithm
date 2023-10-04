#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

ll n, k, l, r;
ll check[100001];
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector<ll> v;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	ll ret = 0;
	while (r < v.size())
	{
		if (check[v[r]])
		{
			ret += (r - l);
			check[v[l]] = 0;
			l++;
		}
		else
		{
			check[v[r]] = 1;
			r++;
		}
	}
	ret += (ll)(r - l) * (r - l + 1) / 2;
	cout << ret;

	return 0;
}