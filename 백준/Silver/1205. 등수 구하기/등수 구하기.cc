#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, s, p;
	cin >> n >> s >> p;
	vector<ll> v;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.rbegin(), v.rend());

	ll rank = 1;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > s)
		{
			rank++;
		}
		if (v[i] == s && i < p) {
			rank = i + 1;
			break;
		}
	}
	if (v.size() == p && v.back() == s||rank>p)
	{
		cout << -1;
	}
	else cout << rank;
	return 0;
}
